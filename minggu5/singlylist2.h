#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
#include <cstdlib>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

// Soal 3
address findElm(List L, infotype x);

// Soal 4
int sumInfo(List L);

#endif