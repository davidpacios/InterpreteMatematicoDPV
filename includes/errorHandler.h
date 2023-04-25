#ifndef CM1_ERRORHANDLER_H
#define CM1_ERRORHANDLER_H

#define ERROR_CODE 1
#define ERROR_INCOMPLETE_TOKEN_DUETO_BLOCKSIZE 2

void errorInvalidSyntax(int lineError);

void errorCantAssign(int lineError);

void errorVariableNotDeclared(int lineError);

void errorFunctionNotImported(int lineError);

void errorInvalidOperator(int lineError);

void errorFunctionParameter(int lineError);

void errorOperationNoNumbers(int lineError);

void errorCleaningVariable(int lineError);

void errorFileAlreadyOpen(char *fileName, int lineError);

void errorCannotOpenFile(char *fileName, int lineError);

void errorCannotImportLibrary(char *libraryName, int lineError);

void errorCannotImportFunction(char *functionName, int lineError);

#endif //CM1_ERRORHANDLER_H
