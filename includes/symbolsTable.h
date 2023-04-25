#ifndef CM1_SYMBOLSTABLE_H
#define CM1_SYMBOLSTABLE_H

#include "hashTableRelocation.h"

/********** TOKENS **********/

#define ID_TABLE 500
#define FUNCTION_TABLE 501
#define CONST_TABLE 502

void initSymbolsTable();

void printSymbolsTable();

void clearSymbolsTable();

void destroySymbolsTable();

int isSymbol(char *stringToken, int codeToken);

void insertSymbol(char *stringToken, int codeToken, double value, double (*function)());

void modifySymbol(char *stringToken, int codeToken, double value, double (*function)());

double recoverSymbol(char *stringToken);

void removeSymbol(char *stringToken);

double callFunction(char *stringToken , void* param1, void* param2);


#endif //CM1_SYMBOLSTABLE_H
