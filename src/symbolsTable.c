#include <stdio.h>
#include <math.h>
#include "../includes/symbolsTable.h"

TablaHash TS;

/********** CONSTS **********/
#define TOTAL_CONSTS 2

//Palabras reservadas del lenguaje D (https://dlang.org/spec/lex.html)
token constsElements[TOTAL_CONSTS] =
        {
            {{3.141592},"pi", CONST_TABLE},
            {{2.718281},"e", CONST_TABLE},
        };

void initSymbolsTable() {
    InitHashTable(TS);
    for (int i = 0; i < TOTAL_CONSTS; i++) {
        insertSymbol(constsElements[i].stringToken,CONST_TABLE ,constsElements[i].data.value , NULL);
    }
    insertSymbol("^", FUNCTION_TABLE, 0, pow); //Necesario

    // insertSymbol("sin", FUNCTION_TABLE, 0, sin);
    // insertSymbol("cos", FUNCTION_TABLE, 0, cos);
    // insertSymbol("tan", FUNCTION_TABLE, 0, tan);
    // insertSymbol("asin", FUNCTION_TABLE, 0, asin);
    // insertSymbol("acos", FUNCTION_TABLE, 0, acos);
    // insertSymbol("atan", FUNCTION_TABLE, 0, atan);
    // insertSymbol("sinh", FUNCTION_TABLE, 0, sinh);
    // insertSymbol("cosh", FUNCTION_TABLE, 0, cosh);
    // insertSymbol("tanh", FUNCTION_TABLE, 0, tanh);
    // insertSymbol("asinh", FUNCTION_TABLE, 0, asinh);
    // insertSymbol("acosh", FUNCTION_TABLE, 0, acosh);
    // insertSymbol("atanh", FUNCTION_TABLE, 0, atanh);
    // insertSymbol("exp", FUNCTION_TABLE, 0, exp);
    // insertSymbol("log", FUNCTION_TABLE, 0, log);
    // insertSymbol("log10", FUNCTION_TABLE, 0, log10);
    // insertSymbol("sqrt", FUNCTION_TABLE, 0, sqrt);
    // insertSymbol("cbrt", FUNCTION_TABLE, 0, cbrt);
    // insertSymbol("ceil", FUNCTION_TABLE, 0, ceil);
    // insertSymbol("floor", FUNCTION_TABLE, 0, floor);
    // insertSymbol("fabs", FUNCTION_TABLE, 0, fabs);
    // insertSymbol("rint", FUNCTION_TABLE, 0, rint);
    // insertSymbol("round", FUNCTION_TABLE, 0, round);
    // insertSymbol("trunc", FUNCTION_TABLE, 0, trunc);
    // insertSymbol("fmod", FUNCTION_TABLE, 0, fmod);
}

void printSymbolsTable() {
    printf("\nSymbols Table (TS):\n");
    printHashTable(TS);
    printf("\n");
}

void clearSymbolsTable() {
    printf("\nClearing Symbols Table (TS)...\n");
    destroyHashTableID(TS);
    printf("Symbols Table (TS) cleared successfully!\n");
    printf("\n");
}

void destroySymbolsTable(){
    printf("\nDestroying Symbols Table (TS)...\n");
    destroyHashTable(TS);
    printf("Symbols Table (TS) destroyed successfully!\n");
    printf("\n");
}

int isSymbol(char *stringToken, int codeToken) {
    if(codeToken == -1)
        return isElementOnHash(TS, stringToken);

    return isElementOnHashWithCode(TS, stringToken, codeToken);
}


void modifySymbol(char *stringToken, int codeToken, double newValue, double (*function)()) {
    if(isSymbol(stringToken, ID_TABLE))
        modifyHashElement(TS,stringToken,newValue,NULL);

    else if(isSymbol(stringToken, FUNCTION_TABLE))
        modifyHashElement(TS,stringToken,0,function);

}

void insertIDSymbol(char *stringToken,double value) {
    token t;
    t.stringToken = stringToken;
    t.codeToken = ID_TABLE;
    t.data.value = value;

    if (isSymbol(stringToken, ID_TABLE)) {
        modifySymbol(stringToken, ID_TABLE, value, NULL);
        return ;
    }

    insertHashElement(TS, t);
}

void insertFuncSymbol(char *stringToken, double (*function)()) {
    token t;
    t.stringToken = stringToken;
    t.codeToken = FUNCTION_TABLE;
    t.data.function = function;

    if (isSymbol(stringToken, FUNCTION_TABLE)) {
        modifySymbol(stringToken, FUNCTION_TABLE, 0, function);
        return ;
    }

    insertHashElement(TS, t);
}

void insertSymbol(char *stringToken, int codeToken, double value, double (*function)()) {
    token t;
    switch (codeToken) {
        case ID_TABLE:
            insertIDSymbol(stringToken, value);
            break;
        case FUNCTION_TABLE:
            insertFuncSymbol(stringToken, function);
            break;
        case CONST_TABLE:
            t.stringToken = stringToken;
            t.codeToken = CONST_TABLE;
            t.data.value = value;
            insertHashElement(TS, t);
            break;
        default:
            printf("Error: %s is not a valid symbol!\n", stringToken);
            break;
    }
}


double recoverSymbol(char *stringToken){
    token e;
    if(searchHashElement(TS, stringToken, &e)){
        if(e.codeToken == ID_TABLE || e.codeToken == CONST_TABLE)
            return e.data.value;
        else if(e.codeToken == FUNCTION_TABLE)
            return e.data.function();
    }
    return 0;
}


void removeSymbol(char *stringToken){
    if(isSymbol(stringToken, ID_TABLE) || isSymbol(stringToken, FUNCTION_TABLE))
        destroyHashElement(TS, stringToken);
}

double callFunction(char *stringToken, void* param1, void* param2){
    token e;
    if(searchHashElement(TS, stringToken, &e)){
        if(e.codeToken == FUNCTION_TABLE){
            if(param1 != NULL && param2 != NULL){
                double p1 = *(double*)param1;
                double p2 = *(double*)param2;
                return e.data.function(p1, p2);
            }

            if(param1 != NULL){
              double p1 = *(double*)param1;
                return e.data.function(p1);
            }
        }
    }
    return 0;
}


