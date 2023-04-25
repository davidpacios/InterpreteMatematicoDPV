%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <dlfcn.h>
#include "../includes/lexicalAnalysis.yy.h"
#include "../includes/symbolsTable.h"
#include "../includes/errorHandler.h"

void openFile(char* fileName);

int areNumbers(double a, double b);

void printPrompt();

void comparisonFunction(double a, int op, double b);
double operationFunction(double a, int op, double b);
void assignmentFunction(char* a, int op, double b, double* result);
double functionFunction(char* a, double*b,double*c);

void IMPORTCommand(char* library, char* functionName);
void ECHOCommand();
void HELPCommand();

void yyerror(char* s);

int echoControler = 1;
int printPromptControler = 1;

%}

%union {
char* stringToken;
double numberToken;
};

//Start
%start input;

//Input
%token <stringToken> ID
%token <stringToken> FILE_TO_READ
%token <stringToken> LIBRARY_FILE
%token <numberToken> NUMBER

//Operations
%token WORKSPACE CLEAN_WORKSPACE CLEAN_VAR IMPORT LOAD  HELP CLEAR ECHOPRINT END_OF_FILE


//Operators
%token ASSIGN_OPERATOR ADD_ASSIGN_OPERATOR SUB_ASSIGN_OPERATOR MUL_ASSIGN_OPERATOR DIV_ASSIGN_OPERATOR ADD_ADD_OPERATOR SUB_SUB_OPERATOR GREATER_EQUAL_OPERATOR LESS_EQUAL_OPERATOR EQUAL_EQUAL_OPERATOR NOT_EQUAL_OPERATOR

//Special operators
%right ASSIGN_OPERATOR
%left ADD_ASSIGN_OPERATOR SUB_ASSIGN_OPERATOR MUL_ASSIGN_OPERATOR DIV_ASSIGN_OPERATOR ADD_ADD_OPERATOR SUB_SUB_OPERATOR GREATER_EQUAL_OPERATOR LESS_EQUAL_OPERATOR EQUAL_EQUAL_OPERATOR NOT_EQUAL_OPERATOR

//OJO LA NEGACION

//Simple operators
%right '^'
%left '+' '-'
%left '*' '/' '%' '<' '>'


%type <numberToken> expression
%type <numberToken> operation
%type <numberToken> comparison
%type <numberToken> assignment
%type <numberToken> function
%type <numberToken> commands

//Con error sintactico liberamos memoria
%destructor {free($$);} <stringToken>

%%

input:
    {printPrompt();}
    | input line
;

line:
    '\n'  {printPrompt();}
    | expression ';' '\n' {printPrompt();}
    | expression '\n' {if(echoControler && printPromptControler){if(!isnan($1)){printf("%.4lf\n",$1);}}printPrompt();}
    | expression END_OF_FILE {printPromptControler = 1;printPrompt();}
    | END_OF_FILE {printPromptControler = 1;printPrompt();}
    | error '\n' {printPrompt();}
;

expression:
    '(' expression ')' { $$ = $2;}

    | '+' expression {$$ = $2;}
    | '-' expression {$$ = -$2;}

    | NUMBER {$$ = $1;}
    | ID {if(isSymbol($1,ID_TABLE)|isSymbol($1,CONST_TABLE)){$$ = recoverSymbol($1);}else if(isSymbol($1,FUNCTION_TABLE)){errorFunctionParameter(yylineno);$$ = NAN;}else{errorVariableNotDeclared(yylineno);$$ = NAN;}free($1);}

    | operation
    | comparison
    | assignment
    | function
    | commands
;

operation:
    expression '+' expression {if(areNumbers($1,$3)){$$ = operationFunction($1,'+',$3);}else{errorOperationNoNumbers(yylineno);$$ = NAN;}}
    | expression '-' expression {if(areNumbers($1,$3)){$$ = operationFunction($1,'-',$3);}else{errorOperationNoNumbers(yylineno);$$ = NAN;}}
    | expression '*' expression {if(areNumbers($1,$3)){$$ = operationFunction($1,'*',$3);}else{errorOperationNoNumbers(yylineno);$$ = NAN;}}
    | expression '/' expression {if(areNumbers($1,$3)){$$ = operationFunction($1,'/',$3);}else{errorOperationNoNumbers(yylineno);$$ = NAN;}}
    | expression '%' expression {if(areNumbers($1,$3)){$$ = operationFunction($1,'%',$3);}else{errorOperationNoNumbers(yylineno);$$ = NAN;}}
;

comparison:
    expression GREATER_EQUAL_OPERATOR expression {if(areNumbers($1,$3)){comparisonFunction($1,GREATER_EQUAL_OPERATOR,$3);}else{errorOperationNoNumbers(yylineno);}$$ = NAN;}
    | expression LESS_EQUAL_OPERATOR expression {if(areNumbers($1,$3)){comparisonFunction($1,LESS_EQUAL_OPERATOR,$3);}else{errorOperationNoNumbers(yylineno);}$$ = NAN;}
    | expression EQUAL_EQUAL_OPERATOR expression {if(areNumbers($1,$3)){comparisonFunction($1,EQUAL_EQUAL_OPERATOR,$3);}else{errorOperationNoNumbers(yylineno);}$$ = NAN;}
    | expression NOT_EQUAL_OPERATOR expression {if(areNumbers($1,$3)){comparisonFunction($1,NOT_EQUAL_OPERATOR,$3);}else{errorOperationNoNumbers(yylineno);}$$ = NAN;}
    | expression '<' expression {if(areNumbers($1,$3)){comparisonFunction($1,'<',$3);}else{errorOperationNoNumbers(yylineno);}$$ = NAN;}
    | expression '>' expression {if(areNumbers($1,$3)){comparisonFunction($1,'>',$3);}else{errorOperationNoNumbers(yylineno);}$$ = NAN;}
;

assignment:
     ID ASSIGN_OPERATOR expression {assignmentFunction($1,ASSIGN_OPERATOR,$3,&($$));free($1);}
    | ID ADD_ASSIGN_OPERATOR expression {assignmentFunction($1,ADD_ASSIGN_OPERATOR,$3,&($$));free($1);}
    | ID SUB_ASSIGN_OPERATOR expression {assignmentFunction($1,SUB_ASSIGN_OPERATOR,$3,&($$));free($1);}
    | ID MUL_ASSIGN_OPERATOR expression {assignmentFunction($1,MUL_ASSIGN_OPERATOR,$3,&($$));free($1);}
    | ID DIV_ASSIGN_OPERATOR expression {assignmentFunction($1,DIV_ASSIGN_OPERATOR,$3,&($$));free($1);}
    | ID ADD_ADD_OPERATOR {assignmentFunction($1,ADD_ADD_OPERATOR,1,&($$));free($1);}
    | ID SUB_SUB_OPERATOR {assignmentFunction($1,SUB_SUB_OPERATOR,-1,&($$));free($1);}
;

function:
    ID '(' expression ')' {$$ = functionFunction($1,&($3),NULL);free($1);}
    | ID '(' expression ',' expression ')' {$$ = functionFunction($1,&($3),&($5));free($1);}
    | expression '^' expression {char*aux = (char*)malloc(sizeof(char)*2);aux[0] ='^';aux[1] ='\0';$$ = functionFunction(aux,&($1),&($3));free(aux);}
;

commands:
    WORKSPACE {printSymbolsTable(); $$ = NAN;}
    | CLEAN_WORKSPACE {clearSymbolsTable(); $$ = NAN;}
    | CLEAN_VAR ID {if(isSymbol($2,ID_TABLE)){removeSymbol($2);}else{errorCleaningVariable(yylineno);} $$ = NAN;free($2);}
    | HELP {HELPCommand(); $$ = NAN;}
    | CLEAR {system("clear"); $$ = NAN;}
    | LOAD FILE_TO_READ {if(printPromptControler)printf("Loading %s ...\n\n\n",$2); openFile($2); $$ = NAN;free($2); printPromptControler = 0;}
    | IMPORT LIBRARY_FILE ID {IMPORTCommand($2,$3); $$ = NAN;free($2);free($3);}
    | ECHOPRINT {ECHOCommand(); $$ = NAN;}
%%

int areNumbers(double a, double b){
    if(isnan(a) || isnan(b)){
        return 0;
    }
    return 1;
}

void comparisonFunction(double a,int op,double b){
    int aux = 0;
    switch(op){
        case '>':
            if(a>b){aux = 1;break;}
            break;

        case '<':
            if(a<b){aux = 1;break;}
            break;

        case GREATER_EQUAL_OPERATOR:
            if(a>=b){aux = 1;break;}
            break;

        case LESS_EQUAL_OPERATOR:
            if(a<=b){aux = 1;break;}
            break;

        case EQUAL_EQUAL_OPERATOR:
            if(a==b){aux = 1;break;}
            break;

        case NOT_EQUAL_OPERATOR:
            if(a!=b){aux = 1;break;}
            break;

        default:
            errorInvalidOperator(yylineno);
            break;
    }

    if(echoControler){
        if(aux){
            printf("True\n");
            return;
        }
        printf("False\n");
        return;
    }

}

double operationFunction(double a,int op,double b){
    switch(op){
        case '+':
            return a+b;

        case '-':
            return a-b;

        case '*':
            return a*b;

        case '/':
            return a/b;

        case '%':
            return (int)a%(int)b;

        default:
            errorInvalidOperator(yylineno);
            return NAN;
    }
}

void assignmentFunction(char* a,int op,double b,double* result){
    if(isSymbol(a,CONST_TABLE)||isSymbol(a,FUNCTION_TABLE)){
        errorCantAssign(yylineno);
        *result = NAN;
        return;
    }
    if(op != ASSIGN_OPERATOR && !isSymbol(a,ID_TABLE)){
        errorVariableNotDeclared(yylineno);
        *result = NAN;
        return;
    }

    if(!areNumbers(b,b)){
        errorOperationNoNumbers(yylineno);
        *result = NAN;
        return;
    }

    switch(op){
        case ASSIGN_OPERATOR:
            insertSymbol(a,ID_TABLE,b,NULL);
            *result = b;

            return;

        case ADD_ASSIGN_OPERATOR:
            *result = recoverSymbol(a)+b;
            insertSymbol(a,ID_TABLE,*result,NULL);

            return;

        case SUB_ASSIGN_OPERATOR:
            *result = recoverSymbol(a)-b;
            insertSymbol(a,ID_TABLE,*result,NULL);

            return;

        case MUL_ASSIGN_OPERATOR:
            *result = recoverSymbol(a)*b;
            insertSymbol(a,ID_TABLE,*result,NULL);
            
            return;

        case DIV_ASSIGN_OPERATOR:
            *result = recoverSymbol(a)/b;
            insertSymbol(a,ID_TABLE,*result,NULL);

            return;

        case ADD_ADD_OPERATOR:
            *result = recoverSymbol(a)+b;
            insertSymbol(a,ID_TABLE,*result,NULL);

            return;

        case SUB_SUB_OPERATOR:
            *result = recoverSymbol(a)-b;
            insertSymbol(a,ID_TABLE,*result,NULL);

            return;

        default:
            errorInvalidOperator(yylineno);
            *result = NAN;
            return;
    }
}

double functionFunction(char* a,double* b,double* c){
    if(!isSymbol(a,FUNCTION_TABLE)){
        errorFunctionNotImported(yylineno);
        return NAN;
    }

    return callFunction(a, b, c);
}

void printPrompt(){
    if(printPromptControler){
        printf(">>>DPV>>>");
        yylineno = -1;
    }
        
}

void IMPORTCommand(char* library, char* functionName){
    printf("Importing %s from %s...\n",functionName,library);

    void *handle = dlopen(library, RTLD_LAZY);
    if (!handle) errorCannotImportLibrary(library,yylineno);
    
    double (*function) (double) = dlsym(handle, functionName);
    if (!function) errorCannotImportFunction(functionName,yylineno);

    insertSymbol(functionName,FUNCTION_TABLE,NAN,function);
}

void ECHOCommand(char* s){
    echoControler = (echoControler+1) % 2;
    if(echoControler){
        printf("Echo is ON\n");
    }else{
        printf("Echo is OFF\n");
    }
}

void HELPCommand(){
    printf(">>>DPV>>>Help:\n");
    printf(">>>DPV>>>This is a simple calculator that can do basic operations and comparisons.\n");
    printf(">>>DPV>>>You can assign values to variables and use them in the future.\n");
    printf(">>>DPV>>>You can use functions, at the start you can only use ^. To add more use import command.\n");
    printf(">>>DPV>>>You can use the following commands:\n");
    printf(">>>DPV>>>   echo: Turn on/off the echo.\n");
    printf(">>>DPV>>>   load <file.dpv>: Load a file.\n");
    printf(">>>DPV>>>   import <library.so> <function>: Import a function from a library.(Ex:import libm.so.6 cos).\n");
    printf(">>>DPV>>>   workspace: Print the current workspace.\n");
    printf(">>>DPV>>>   clean workspace: Clean the current workspace.\n");
    printf(">>>DPV>>>   clean <var>: Clean a variable.\n");
    printf(">>>DPV>>>   clear: Clear the screen.\n");
    printf(">>>DPV>>>   help: Print this help.\n");
    printf(">>>DPV>>>   exit: Exit the program.\n");
}

void yyerror(char* s){
    if(yylineno == 0 || yylineno == -1){
        printf("Error on command line: %s\n",s);
        return;
    }
    printf("Error on line %d: %s\n",yylineno,s);
}





