# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Muhammad Azhar Nur Hafizh - 109082500049</p>

## Dasar Teori
Linked list atau yang disebut juga senarai berantai adalah salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer.

### A. Linked List<br/>
 Linked list menyimpan elemen dalam node yang tidak harus berada pada lokasi memori berurutan, sehingga ukurannya dapat berubah sesuai kebutuhan program[1].
#### 1. Pengertian Node
 Setiap node berisi data (info) dan pointer ke node lain. Node terakhir menunjuk ke Nil (NULL) sebagai penanda akhir list[1].
#### 2. Perbandingan dengan Array
 Array dapat diakses langsung lewat indeks tetapi berukuran tetap, sedangkan linked list lebih mudah disisipi dan dihapus elemennya tetapi harus ditelusuri dari node pertama[2].

### B. Singly Linked List<br/>
 Singly linked list adalah linked list yang setiap node-nya hanya memiliki satu pointer (next) ke node berikutnya, sehingga penelusuran hanya satu arah[1].
#### 1. Struktur Node dan List
 Node terdiri dari info dan next, sedangkan list ditunjuk oleh pointer First. Jika First bernilai Nil, list dalam keadaan kosong[1].
#### 2. Alokasi dan Dealokasi
 Dalam C++, node dibuat dengan new dan dibebaskan dengan delete agar tidak terjadi memory leak[2].

### B. Operasi pada Singly Linked List<br/>
 Singly linked list adalah linked list yang setiap node-nya hanya memiliki satu pointer (next) ke node berikutnya, sehingga penelusuran hanya satu arah[1].
#### 1. Insert dan Delete
 insertFirst, insertAfter, dan insertLast menambah node, sedangkan deleteFirst, deleteLast, dan deleteAfter menghapus node. Operasi di awal list atau setelah node tertentu berjalan cepat (O(1)), sedangkan yang harus menelusuri sampai akhir list berjalan O(n). 
#### 2. Traversal
 Penelusuran dilakukan dari First sampai Nil, dipakai oleh printInfo untuk menampilkan isi list, nbList untuk menghitung jumlah node, dan deleteList untuk menghapus seluruh node.

## Guided 

### 1. list.h

```C++
//hear guard digunakan untuk mencegah file header yg sama
//di-include lebih dari sekali dalam 1 program
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked listnya, isis setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedList { //ini linked listnya
    address first;
};

//semua function & prosedure yang akan dipakai
bool isEmpty(linkedList list);
void createList(linkedList &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList list);
void insertFirst(linkedList &list, address nodeBaru);
void insertAfter(linkedList &list, address nodeBaru, address Prev);
void insertLast(linkedList &list, address nodeBaru);

void delFirst(linkedList &list);
void delLast(linkedList &list);
void delAfter(linkedList &list, address nodeHapus, address nodePrev);
int nbList(linkedList list);
void deleteList(linkedList &list);

#endif
```
list.h adalah file header yang mendefinisikan singly linked list untuk menyimpan data mahasiswa. Di dalamnya ada struct mahasiswa (nama, NIM, umur), struct node sebagai simpul yang berisi data dan pointer next, serta struct linkedList yang punya pointer first ke simpul pertama. Sisanya adalah deklarasi fungsi untuk membuat list, menambah simpul (insert), menghapus simpul (delete), menampilkan isi list, dan menghitung jumlah simpul, yang isinya ditulis di list.cpp. Semuanya dibungkus header guard agar file ini tidak ter-include berulang kali.

### 2. list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true;
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedList &List){
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List){
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else {
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev->next, menghapus Prev->next dari list */
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedList List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedList &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}
```
list.cpp berisi isi dari semua fungsi yang dideklarasikan di list.h. createList membuat list kosong dengan mengisi first dengan Nil, isEmpty mengecek apakah list kosong, alokasi membuat node baru dengan new lalu mengisi nama, NIM, dan umur, sedangkan dealokasi menghapus node dari memori dengan delete. Untuk menambah node ada insertFirst (di awal), insertAfter (setelah node tertentu), dan insertLast (di akhir, dengan menelusuri sampai node terakhir). Untuk menghapus ada delFirst (node pertama), delLast (node terakhir), dan delAfter (node setelah node tertentu), yang masing-masing mengecek dulu apakah list kosong atau node sebelumnya valid. Sisanya printList menampilkan semua data mahasiswa, nbList menghitung jumlah node, dan deleteList menghapus seluruh node sampai list kosong lagi.

### 3. main.cpp

```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
main.cpp adalah program utama yang mencoba semua operasi linked list dari list.h dan list.cpp. Pertama, program membuat list kosong dan lima node mahasiswa (Dhimas, Arvin, Rizal, Satrio, Joshua) dengan alokasi. Kelimanya dimasukkan ke list dengan urutan: Dhimas di awal, Arvin di akhir, Rizal setelah Dhimas, Satrio setelah Rizal, dan Joshua di akhir, sehingga urutannya Dhimas, Rizal, Satrio, Arvin, Joshua. Isi list dan jumlah node (5) ditampilkan. Setelah itu program menghapus node pertama (Dhimas), node terakhir (Joshua), dan node setelah Rizal (Satrio), lalu menampilkan sisanya, yaitu Rizal dan Arvin (2 node). Terakhir, seluruh list dihapus dengan deleteList dan ditampilkan lagi untuk memperlihatkan bahwa list sudah kosong dengan jumlah node 0.

### output Unguided 

## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

// ===== Soal 1 =====
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

// ===== Soal 2 =====
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address Prev);
int nbList(List L);
void deleteList(List &L);

#endif
```
Singlylist.h adalah file header yang mendefinisikan ADT singly linked list. Di dalamnya ada tipe infotype (int), address (pointer ke node), ElmList (node berisi info dan next), dan List (berisi pointer First). File ini juga memuat deklarasi semua prosedur, yaitu createList, alokasi, dealokasi, printInfo, insertFirst, deleteFirst, deleteLast, deleteAfter, nbList, dan deleteList.

### 2. Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp”

```C++
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
```

Singlylist.cpp berisi isi dari prosedur-prosedur yang dideklarasikan di header. alokasi membuat node baru dengan new, insertFirst menaruh node di awal list, printInfo menampilkan seluruh isi list, deleteFirst, deleteLast, dan deleteAfter menghapus node di posisi masing-masing, nbList menghitung jumlah node, dan deleteList menghapus semua node sampai list kosong.

### 3. (isi dengan soal unguided 2)

```C++
#include "Singlylist.h"

int main(){
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    // ===== Soal 1 =====
    printInfo(L);
    cout << endl;

    // ===== Soal 2 =====
    deleteFirst(L);       // hapus node 9
    deleteLast(L);        // hapus node 2
    deleteAfter(L, P4);   // hapus node 8 (setelah node 12)

    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;

    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```
### Output Unguided 3 :



main_singlylist.cpp adalah program utama yang menjalankan semuanya. Program membuat list kosong, mengalokasikan lima node (2, 0, 8, 12, 9), lalu menyisipkannya satu per satu dengan insertFirst sehingga list menjadi 9 → 12 → 8 → 0 → 2, dan menampilkannya (soal 1). Setelah itu node 9, 2, dan 8 dihapus, sisa list (12 dan 0) ditampilkan beserta jumlah nodenya, lalu seluruh list dihapus (soal 2).

## Kesimpulan
Dari latihan Modul 4 ini dapat disimpulkan bahwa singly linked list adalah struktur data dinamis yang tersusun dari node-node yang saling terhubung lewat pointer next, dan diakses melalui pointer First yang menunjuk node pertama. Dengan memakai ADT yang dipisahkan menjadi file header (Singlylist.h), file implementasi (Singlylist.cpp), dan program utama (main.cpp), kode menjadi lebih terstruktur dan mudah dipakai ulang. Operasi insert (insertFirst) membuat urutan node berbalik dari urutan penyisipannya, sehingga nilai 2, 0, 8, 12, dan 9 menghasilkan list 9 → 12 → 8 → 0 → 2. Operasi delete (deleteFirst, deleteLast, deleteAfter) berhasil menghapus node pada posisi awal, akhir, dan setelah node tertentu cukup dengan mengubah pointer, tanpa menggeser elemen lain seperti pada array. Penggunaan new dan delete lewat alokasi dan dealokasi juga menunjukkan bahwa memori harus dikelola dengan benar agar tidak terjadi memory leak. Hasil program sesuai dengan output yang diharapkan, yaitu sisa dua node (12 dan 0) setelah penghapusan, dan jumlah node 0 setelah seluruh list dihapus dengan deleteList.

## Referensi
<br>[1] S. Syam, Irawan, N. Janna, S. S. Indasari, dan S. Syam, Struktur Data. Jakarta Barat: PT Bukulokal Literasi Bangsa, (isi tahun).
<br>[2] E. Utami dan W. M. P. Dhuhita, Langkah Mudah Belajar Struktur Data Menggunakan C/C++. Jakarta: PT Elex Media Komputindo, 2017.
