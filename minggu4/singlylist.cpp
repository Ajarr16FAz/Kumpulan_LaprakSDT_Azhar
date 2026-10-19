#include "Singlylist.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

void deleteFirst(List &L) {
    if (L.First != Nil) {
        address P = L.First;
        L.First = P->next;
        P->next = Nil;
        dealokasi(P);
    }
}

void deleteLast(List &L) {
    if (L.First == Nil) {
        return;
    }
    if (L.First->next == Nil) {
        address P = L.First;
        L.First = Nil;
        dealokasi(P);
    } else {
        address Q = L.First;
        while (Q->next->next != Nil) {
            Q = Q->next;
        }
        address P = Q->next;
        Q->next = Nil;
        dealokasi(P);
    }
}

// menghapus node setelah Prev
void deleteAfter(List &L, address Prev) {
    if (Prev != Nil && Prev->next != Nil) {
        address P = Prev->next;
        Prev->next = P->next;
        P->next = Nil;
        dealokasi(P);
    }
}

int nbList(List L) {
    int count = 0;
    address P = L.First;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    while (L.First != Nil) {
        deleteFirst(L);
    }
}