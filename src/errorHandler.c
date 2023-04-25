#include <stdio.h>
#include "../includes/errorHandler.h"

void errorInvalidSyntax(int lineError) {
    if (lineError == 0 || lineError == -1) {
        printf("Error on command line: Invalid syntax\n");
        return;
    }
    printf("Error on line %d: Invalid syntax\n", lineError);
}

void errorCantAssign(int lineError) {
    if (lineError == 0 || lineError == -1) {
        printf("Error on command line: Can't assign to a constant variable or a function\n");
        return;
    }
    printf("Error on line: %d: Can't assign to a constant variable or a function\n", lineError);
}

void errorVariableNotDeclared(int lineError) {
    if (lineError == 0 || lineError == -1) {
        printf("Error on command line: Variable not declared\n");
        return;
    }
    printf("Error on line: %d: Variable not declared\n", lineError);
}

void errorFunctionNotImported(int lineError) {
    if (lineError == 0 || lineError == -1) {
        printf("Error on command line: Function not imported\n");
        return;
    }
    printf("Error on line: %d: Function not imported\n", lineError);
}

void errorInvalidOperator(int lineError) {
    if (lineError == 0 || lineError == -1) {
        printf("Error on command line: Invalid operator\n");
        return;
    }
    printf("Error on line: %d: Invalid operator\n", lineError);
}

void errorFunctionParameter(int lineError) {
    if (lineError == 0 || lineError == -1) {
        printf("Error on command line: Invalid function parameters\n");
        return;
    }
    printf("Error on line: %d: Invalid function parameters\n", lineError);
}

void errorOperationNoNumbers(int lineError) {
    if (lineError == 0 || lineError == -1) {
        printf("Error on command line: Operation with no numbers\n");
        return;
    }
    printf("Error on line: %d: Operation with no numbers\n", lineError);
}

void errorCleaningVariable(int lineError){
    if (lineError == 0 || lineError == -1) {
        printf("Error on command line: Error cleaning variable\n");
        return;
    }
    printf("Error on line: %d: Error cleaning variable\n", lineError);
}

void errorFileAlreadyOpen(char *fileNameTryed, int lineError){
    if (lineError == 0 || lineError == -1) {
        printf("Error on command line: Error can't open file %s, another file is already open\n", fileNameTryed);
        return;
    }
    printf("Error on line: %d: Error can't open file %s, another file is already open\n", lineError, fileNameTryed);
}

void errorCannotOpenFile(char *fileNameTryed, int lineError){
    if (lineError == 0 || lineError == -1) {
        printf("Error on command line: Error can't open file %s\n", fileNameTryed);
        return;
    }
    printf("Error on line: %d: Error can't open file %s\n", lineError, fileNameTryed);
}

void errorCannotImportLibrary(char *libraryNameTryed, int lineError){
    if (lineError == 0 || lineError == -1) {
        printf("Error on command line: Error can't import library %s\n",libraryNameTryed);
        return;
    }
    printf("Error on line: %d: Error can't import library %s\n", lineError, libraryNameTryed);
}

void errorCannotImportFunction(char *functionNameTryed, int lineError){
    if (lineError == 0 || lineError == -1) {
        printf("Error can't import function %s\n",functionNameTryed);
        return;
    }
    printf("Error on line: %d: Error can't import function %s\n", lineError, functionNameTryed);
}






