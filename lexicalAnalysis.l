%{
#include "../includes/symbolsTable.h"
#include "../includes/errorHandler.h"
#include "../includes/syntacticParser.tab.h"

int isValidFile(char* fileName);
void openFile(char* fileName);
void closeFile();

%}

/* OPTIONS */
/*No se genera la función yywrap*/
%option noyywrap 
/*Se cuenta el número de línea*/
%option yylineno
/*No usar yyunput*/
%option nounput
/*No input*/
%option noinput



LETTER [a-zA-Z]
DIGIT [0-9]
NON_ZERO_DIGIT [1-9]

SEPARATOR [ \t]
NO_TOKEN {SEPARATOR}

NEWLINE [\n]

DECIMAL_DIGIT {DIGIT}*
FLOAT_DIGIT {DECIMAL_DIGIT}\.{DIGIT}+
SCIENTIFIC_NOTATION_DIGIT {FLOAT_DIGIT}[eE][+-]?{DECIMAL_DIGIT}+

NUMBER ({DECIMAL_DIGIT}|{FLOAT_DIGIT}|{SCIENTIFIC_NOTATION_DIGIT})

START_ID ([_]|{LETTER})
ID {START_ID}([_]|{LETTER}|{DIGIT})*


SIMPLE_OPERATOR [+\-*/%^,.!><(),;]
ASSIGN_OPERATOR [=]
ADD_ASSIGN_OPERATOR ([+][=])
SUB_ASSIGN_OPERATOR ([-][=])
MUL_ASSIGN_OPERATOR ([*][=])
DIV_ASSIGN_OPERATOR ([/][=])
ADD_ADD_OPERATOR ([+][+])
SUB_SUB_OPERATOR ([-][-])
GREATER_EQUAL_OPERATOR ([>][=])
LESS_EQUAL_OPERATOR ([<][=])
EQUAL_EQUAL_OPERATOR ([=][=])
NOT_EQUAL_OPERATOR ([!][=])

WORKSPACE "workspace"
CLEAN_WORKSPACE "clean workspace"
CLEAN_VAR "clean"
IMPORT "import"
LOAD "load"
CLEAR "clear"
HELP "help"
EXIT "exit"
ECHOPRINT "echo"

FILE_TO_READ ({LETTER}|{DIGIT})*[.]dpv
LIBRARY_FILE ({LETTER}|{DIGIT})*[.]so({LETTER}|{DIGIT}|[.])*

%%

{WORKSPACE} {return (WORKSPACE);}

{ECHOPRINT} {return (ECHOPRINT);}

{IMPORT} {return (IMPORT);}

{LOAD} {return (LOAD);}

{CLEAR} {return (CLEAR);}

{CLEAN_WORKSPACE} {return (CLEAN_WORKSPACE);}

{CLEAN_VAR} {return (CLEAN_VAR);}

{HELP} {return (HELP);}


{EXIT} {if(yyin != stdin)closeFile();yylex_destroy();yyterminate();}


{FILE_TO_READ} {
                yylval.stringToken = (char *)malloc((strlen(yytext)+1)*sizeof(char));
                strncpy(yylval.stringToken,yytext,strlen(yytext));
                yylval.stringToken[strlen(yytext)] = '\0';
                return (FILE_TO_READ);
               }

{LIBRARY_FILE} {
                yylval.stringToken = (char *)malloc((strlen(yytext)+1)*sizeof(char));
                strncpy(yylval.stringToken,yytext,strlen(yytext));
                yylval.stringToken[strlen(yytext)] = '\0';
                return (LIBRARY_FILE);
               }

{ID} {
        yylval.stringToken = (char *)malloc((strlen(yytext)+1)*sizeof(char));
        strncpy(yylval.stringToken,yytext,strlen(yytext));
        yylval.stringToken[strlen(yytext)] = '\0';
        return (ID);
      }

{NUMBER} {
          yylval.numberToken = atof(yytext);
          return(NUMBER);
       }

{NO_TOKEN}

{NEWLINE} {return ((int)*yytext);}

{SIMPLE_OPERATOR} {return ((int)*yytext);}

{ASSIGN_OPERATOR} {return (ASSIGN_OPERATOR);}

{ADD_ASSIGN_OPERATOR} {return (ADD_ASSIGN_OPERATOR);}

{SUB_ASSIGN_OPERATOR} {return (SUB_ASSIGN_OPERATOR);}

{MUL_ASSIGN_OPERATOR} {return (MUL_ASSIGN_OPERATOR);}

{DIV_ASSIGN_OPERATOR} {return (DIV_ASSIGN_OPERATOR);}

{ADD_ADD_OPERATOR} {return (ADD_ADD_OPERATOR);}

{SUB_SUB_OPERATOR} {return (SUB_SUB_OPERATOR);}

{GREATER_EQUAL_OPERATOR} {return (GREATER_EQUAL_OPERATOR);}

{LESS_EQUAL_OPERATOR} {return (LESS_EQUAL_OPERATOR);}

{EQUAL_EQUAL_OPERATOR} {return (EQUAL_EQUAL_OPERATOR);}

{NOT_EQUAL_OPERATOR} {return (NOT_EQUAL_OPERATOR);}

. {errorInvalidSyntax(yylineno);}

<<EOF>> {closeFile(); return(END_OF_FILE);}
%%

/* Funciones */

void openFile(char* fileName){
    if(yyin != stdin){
      errorFileAlreadyOpen(fileName,yylineno);
      return;
      }

    FILE* file = fopen(fileName,"r");
    if(file == NULL){
        errorCannotOpenFile(fileName,yylineno);
        return;    
    }
    yylineno = 1;
    yyin = file;
}

void closeFile(){
    fclose(yyin);
    yyrestart(stdin);
}
