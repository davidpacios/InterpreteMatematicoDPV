#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../includes/hashTableRelocation.h"
#include "../includes/symbolsTable.h"

void InitHashTable(TablaHash t) {
    for (int i = 0; i < N; i++){
        t[i].stringToken = NULL;
    }
}

int hashFunction(char *key) {
    int result = 0;

    for (int i = strlen(key) - 1; i >= 0; i--) {
        result = (result * 256 + key[i]) % N;
    }

    return result;
}

int _searchPosition(TablaHash t, char *cad) {
    int position;
    int a = 1;
    int ini = hashFunction(cad);
    for (int i = 0; i < N; i++) {
        position = (ini + a * i) % N; //Recolocación Simple (a=1)

        if (t[position].stringToken == NULL) return position;

        if (!strncmp(t[position].stringToken, cad, strlen(cad))) return position;

    }
    return ini;
}

int _insertPosition(TablaHash t, char *cad) {
    int position;
    int a = 1;
    int ini = hashFunction(cad);

    for (int i = 0; i < N; i++) {

        position = (ini + a * i) % N; //Recolocación Simple (a=1)

        if (t[position].stringToken == NULL) return position;

        if (!strncmp(t[position].stringToken, cad, strlen(cad))) return position;
    }

    return ini;
}

int isElementOnHashWithCode(TablaHash t, char *key, int codeToken) {
    int position = _searchPosition(t, key);

    if (t[position].stringToken == NULL) return 0;

    if (!strncmp(t[position].stringToken, key, strlen(key)) && t[position].codeToken == codeToken) return 1;

    return 0;

}

int isElementOnHash(TablaHash t, char *key) {
    int position = _searchPosition(t, key);

    if (t[position].stringToken == NULL) return 0;

    if (!strncmp(t[position].stringToken, key, strlen(key))) return 1;

    return 0;

}

int searchHashElement(TablaHash t, char* key, token *e) {
    int position = _searchPosition(t, key);

    if (t[position].stringToken == NULL) return 0;

    if (!strncmp(t[position].stringToken, key, strlen(key))) { *e = t[position]; return 1;}

    return 0;

}

void insertHashElement(TablaHash t, token e) {
    int position = _insertPosition(t, e.stringToken);

    if (t[position].stringToken == NULL){
        t[position].stringToken = (char *) malloc(strlen(e.stringToken) + 1);
        strcpy(t[position].stringToken, e.stringToken);
        t[position].codeToken = e.codeToken;
        t[position].data = e.data;
        return;
    }
}

void modifyHashElement(TablaHash t, char *key, double newValueID,double (*newValueFunction)()) {
    int position = _searchPosition(t, key);

    if (t[position].stringToken == NULL) return;

    if (!strncmp(t[position].stringToken, key, strlen(key))) {
        if(t[position].codeToken == ID_TABLE){
            t[position].data.value = newValueID;
            return;
        }else if(t[position].codeToken == FUNCTION_TABLE){
            t[position].data.function = newValueFunction;
            return;
        }
        printf("Error: %s is a CONST or FUNCTION!\n", t[position].stringToken);
        return;
    }
}

void destroyHashElement(TablaHash t, char *key) {
    int position = _searchPosition(t, key);

    if (t[position].stringToken == NULL) return;

    if (!strncmp(t[position].stringToken, key, strlen(key))) {

        if(t[position].codeToken == ID_TABLE){
            free(t[position].stringToken);
            t[position].stringToken = NULL;
            return;
        }
    }
}

void destroyHashTableID(TablaHash t) {
    for (int i = 0; i < N; i++) {
        if(t[i].stringToken != NULL && t[i].codeToken == ID_TABLE){
            free(t[i].stringToken);
            t[i].stringToken = NULL;
        }
    }
}

void destroyHashTable(TablaHash t) {
    for (int i = 0; i < N; i++) {
        if(t[i].stringToken != NULL){
            free(t[i].stringToken);
            t[i].stringToken = NULL;
        }
    }
}

void printHashTable(TablaHash t) {
    for (int i = 0; i < N; i++) {
        if (t[i].stringToken != NULL) {
            printf("Posicion %d: %s, %d, %f\n", i, t[i].stringToken, t[i].codeToken, t[i].data.value);
        }
    }
}