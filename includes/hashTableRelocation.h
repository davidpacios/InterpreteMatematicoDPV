#ifndef CM1_HASHTABLERELOCATION_H
#define CM1_HASHTABLERELOCATION_H

#define N 223
/*El factor de carga es L=n/N, se recomienda L entre 0,5 y 0,75, es decir, N entre 2n y 4n/3 y que sea primo.
Teniendo en cuenta 102 palabras reservadas y 30 ID de media -> 132 elementos, TH de tamaño (2*132,4*132/3) -> (264,176) elementos.*/

union info{
    double value;
    double (*function)();
};

typedef struct{
    union info data;
    char *stringToken;
    short codeToken;

}token;

typedef token TablaHash[N];

void InitHashTable(TablaHash t);

int hashFunction(char *key);

int isElementOnHashWithCode(TablaHash t, char *key, int codeToken);

int isElementOnHash(TablaHash t, char *key);

int searchHashElement(TablaHash t, char *key, token *e);

void insertHashElement(TablaHash t, token e);

void modifyHashElement(TablaHash t, char *key, double newValueID, double (*newValueFunction)());

void destroyHashElement(TablaHash t, char *key);

void destroyHashTableID(TablaHash t);

void destroyHashTable(TablaHash t);

void printHashTable(TablaHash t);

#endif //CM1_HASHTABLERELOCATION_H
