# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Muhammad Azhar Nur Hafizh - 109082500049</p>

## Dasar Teori

### A. Doubly Linked List<br/>
1. Doubly linked list adalah struktur data linier yang setiap node-nya memiliki dua pointer, yaitu next yang menunjuk ke node berikutnya dan prev yang menunjuk ke node sebelumnya [5].
2. Berbeda dengan singly linked list yang hanya memiliki pointer ke node berikutnya, doubly linked list memungkinkan penelusuran dua arah (maju dan mundur), sehingga penyisipan dan penghapusan data menjadi lebih mudah [5].
3. Setiap node terdiri dari tiga bagian, yaitu data (info), pointer next, dan pointer prev.
4. List menyimpan dua penunjuk, yaitu First yang menunjuk node pertama dan Last yang menunjuk node terakhir. List kosong jika First bernilai Nil (NULL).
5. Pointer prev pada node pertama dan pointer next pada node terakhir bernilai Nil sebagai penanda ujung list.

### B. Abstract Data Type (ADT) Doubly Linked List<br/>
1. ADT mendefinisikan struktur data beserta operasi-operasinya sebagai satu kesatuan.
2. Pada tugas ini, ADT dipisah menjadi file header (.h) yang berisi tipe data dan prototype fungsi, serta file implementasi (.cpp) yang berisi isi fungsi, lalu diuji pada file main.cpp.
3. Struktur yang digunakan:
    infotype: data yang disimpan (misalnya kode buku, judul, tahun terbit)
    ElmList: node (berisi info, next, dan prev)
    address: pointer ke ElmList
    List: struktur yang berisi First dan Last

### C. Operasi Dasar dan Penambahan Data<br/>
Operasi dasar meliputi CreateList untuk membuat list kosong (First dan Last diisi Nil), alokasi untuk membuat node baru secara dinamis dengan operator new, dealokasi untuk membebaskan memori dengan operator delete, dan printInfo untuk menampilkan data dengan menelusuri list. Fungsi insertLast menambahkan node di akhir list: jika list kosong, node baru menjadi First sekaligus Last, jika tidak, prev node baru diarahkan ke Last lama, next Last lama diarahkan ke node baru, lalu Last diperbarui. Penyisipan pada doubly linked list dapat dilakukan di awal, di akhir, maupun di tengah list [5].

### D. Searching pada Doubly Linked List
Searching dilakukan dengan menelusuri node dari First menggunakan pointer next sambil membandingkan data yang dicari (pada tugas ini kodeBuku atau nopol) dengan info pada setiap node. Fungsi findElm mengembalikan alamat node yang cocok, atau Nil jika tidak ditemukan. Metode ini disebut linear search dengan kompleksitas waktu O(n), karena pada kasus terburuk seluruh node harus diperiksa. Pada tugas ini, pencarian juga dipakai untuk mengecek duplikasi sebelum data baru dimasukkan.

### E. Penghapusan Data (Delete)
Penghapusan pada doubly linked list dapat dilakukan di awal, di akhir, maupun di tengah list [5]. deleteFirst melepas node pertama lalu memajukan First, deleteLast melepas node terakhir lalu memundurkan Last, dan deleteAfter melepas node yang berada tepat setelah node Prec dengan menyambungkan kembali pointer next dan prev di sekitarnya. Jika list hanya berisi satu node, First dan Last dikembalikan menjadi Nil. Keberadaan pointer prev membuat node sebelumnya dapat dicapai langsung tanpa penelusuran ulang dari awal, sehingga penghapusan menjadi lebih efisien dibanding singly linked list. Setelah node dilepas, memorinya dibebaskan dengan dealokasi.

## Guided 

### 1. doublylist.h

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>

#define Nil NULL

// Latihan 1
struct infotype {
    std::string nopol; 
    std::string warna; 
    int thnBuat;      
};
typedef struct elmlist *address;
struct elmlist {
    infotype info;  
    address next;   
    address prev;   
};
struct List {
    address First; 
    address Last;  
};


// Latihan 1
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

// Latihan 2

address findElm(List L, std::string nopol);

// Latihan 3
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteElm(List &L, std::string nopol, bool &status);

#endif
```

### 2. doublylist.cpp

```C++
#include "doublylist.h"

// Latihan 1
void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil; 
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void printInfo(List L) {
    address P = L.Last;
    if (P == Nil) {
        std::cout << "List kosong." << std::endl;
        return;
    }
    while (P != Nil) {
        std::cout << "no polisi : " << P->info.nopol << std::endl;   
        std::cout << "warna     : " << P->info.warna << std::endl;   
        std::cout << "tahun     : " << P->info.thnBuat << std::endl; 
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    if (L.First == Nil) { 
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;         
        (L.Last)->next = P;     
        L.Last = P;               
    }
}

// Latihan 2
address findElm(List L, std::string nopol) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

// Latihan 3
void deleteFirst(List &L, address &P) {
    if (L.First == Nil) return;

    P = L.First; 
    if (L.First == L.Last) { 
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.First = P->next;     
        (L.First)->prev = Nil; 
        P->next = Nil;         
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == Nil) return;

    P = L.Last; 
    if (L.First == L.Last) { 
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.Last = P->prev;      
        (L.Last)->next = Nil; 
        P->prev = Nil;         
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec == Nil || Prec->next == Nil) return;

    P = Prec->next;
    if (P == L.Last) {
        deleteLast(L, P);
    } else {
        Prec->next = P->next;     
        (P->next)->prev = Prec; 
        P->next = Nil;            
        P->prev = Nil;           
    }
}

void deleteElm(List &L, std::string nopol, bool &status) {
    address P = findElm(L, nopol);
    status = false;

    if (P != Nil) {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            address Prec = P->prev;
            deleteAfter(L, Prec, P);
        }
        dealokasi(P); 
        status = true;
    }
}
```

### 3. main.cpp

```C++
#include <iostream>
#include "Doublylist.h"
using namespace std;

void inputData(List &L) {
    infotype data;
    address P;

    cout << "masukkan nomor polisi: "; cin >> data.nopol;
    cout << "masukkan warna kendaraan: "; cin >> data.warna;
    cout << "masukkan tahun kendaraan: "; cin >> data.thnBuat;
    if (findElm(L, data.nopol) == Nil) {
        P = alokasi(data); 
        insertLast(L, P);  
    } else {
        cout << "nomor polisi sudah terdaftar" << endl; 
    }
}

int main() {
    List L;
    CreateList(L); 
    address P;

    // Latihan 1
    inputData(L); 
    inputData(L); 
    inputData(L); 
    inputData(L); 

    cout << "\nDATA LIST 1" << endl; 
    printInfo(L); 

    // Latihan 2
    string nopolCari;
    cout << "\nMasukkan Nomor Polisi yang dicari : "; 
    cin >> nopolCari; 
    
    P = findElm(L, nopolCari); 
    if (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl; 
        cout << "Warna        : " << P->info.warna << endl; 
        cout << "Tahun        : " << P->info.thnBuat << endl; 
    } else {
        cout << "Data dengan nomor polisi " << nopolCari << " tidak ditemukan." << endl;
    }

    // Latihan 3
    string nopolHapus;
    bool hapusBerhasil;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> nopolHapus;

    deleteElm(L, nopolHapus, hapusBerhasil); 

    if (hapusBerhasil) {
        cout << "Data dengan nomor polisi " << nopolHapus << " berhasil dihapus." << endl; 
    } else {
        cout << "Data dengan nomor polisi " << nopolHapus << " tidak ditemukan." << endl;
    }
    cout << "\nDATA LIST 1" << endl; 
    printInfo(L); 

    return 0;
}

```
Program ini menyimpan data buku (kode, judul, tahun terbit) dalam doubly linked list. buku.h berisi struktur data dan daftar fungsi, buku.cpp berisi isi fungsinya (buat list, alokasi, cetak, tambah di akhir, cari, dan tiga jenis hapus), dan bukumain.cpp menjalankan alurnya: input data dengan pengecekan kode ganda, mencari satu buku, lalu menghapus satu buku.

### output Unguided 

![Output Guided]!(foto/foto_guided.png)


## Unguided 

### 1. 

```C++
#ifndef BUKU_H_INCLUDED
#define BUKU_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct buku {
    string kodeBuku;
    string judul;
    int thnTerbit;
};

typedef buku infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

// Soal 1
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

// Soal 2
address findElm(List L, infotype x);

// Soal 3
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif // BUKU_H_INCLUDED
```

### 2. Cari elemen dengan info 8

```C++
#include "buku.h"

void CreateList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

// Mencetak dari elemen terakhir ke pertama (sesuai contoh output)
void printInfo(List L) {
    address P = L.Last;
    while (P != NULL) {
        cout << "Kode Buku    : " << P->info.kodeBuku << endl;
        cout << "Judul        : " << P->info.judul << endl;
        cout << "Tahun Terbit : " << P->info.thnTerbit << endl;
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

// Mencari elemen berdasarkan kodeBuku
address findElm(List L, infotype x) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.kodeBuku == x.kodeBuku) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void deleteFirst(List &L, address &P) {
    if (L.First == NULL) {
        P = NULL;
    } else if (L.First == L.Last) {
        P = L.First;
        L.First = NULL;
        L.Last = NULL;
    } else {
        P = L.First;
        L.First = P->next;
        L.First->prev = NULL;
        P->next = NULL;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == NULL) {
        P = NULL;
    } else if (L.First == L.Last) {
        P = L.Last;
        L.First = NULL;
        L.Last = NULL;
    } else {
        P = L.Last;
        L.Last = P->prev;
        L.Last->next = NULL;
        P->prev = NULL;
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec == NULL || Prec->next == NULL) {
        P = NULL;
    } else {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != NULL) {
            P->next->prev = Prec;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}
```

### 3. Hitung total info seluruh elemen

```C++
#include "buku.h"

int main() {
    List L;
    CreateList(L);

    // ===== Soal 1: Insert data (cek duplikasi kodeBuku) =====
    int jumlah = 4;
    for (int i = 0; i < jumlah; i++) {
        infotype x;
        cout << "masukkan kode buku: ";
        cin >> x.kodeBuku;
        cout << "masukkan judul buku: ";
        cin >> x.judul;
        cout << "masukkan tahun terbit: ";
        cin >> x.thnTerbit;

        if (findElm(L, x) != NULL) {
            cout << "kode buku sudah terdaftar";
        } else {
            address P = alokasi(x);
            insertLast(L, P);
        }
    }

    cout << "DATA LIST 1" << endl;
    printInfo(L);
    cout << endl;

    // ===== Soal 2: Searching =====
    infotype cari;
    cout << "Masukkan Kode Buku yang dicari : ";
    cin >> cari.kodeBuku;
    address hasil = findElm(L, cari);
    if (hasil != NULL) {
        cout << "Kode Buku    : " << hasil->info.kodeBuku << endl;
        cout << "Judul        : " << hasil->info.judul << endl;
        cout << "Tahun Terbit : " << hasil->info.thnTerbit << endl;
    } else {
        cout << "Data dengan kode buku " << cari.kodeBuku << " tidak ditemukan." << endl;
    }
    cout << endl;

    // ===== Soal 3: Delete =====
    infotype hapus;
    cout << "Masukkan Kode Buku yang akan dihapus : ";
    cin >> hapus.kodeBuku;
    address target = findElm(L, hapus);
    if (target == NULL) {
        cout << "Data dengan kode buku " << hapus.kodeBuku << " tidak ditemukan." << endl;
    } else {
        address P = NULL;
        if (target == L.First) {
            deleteFirst(L, P);
        } else if (target == L.Last) {
            deleteLast(L, P);
        } else {
            deleteAfter(target->prev, P);
        }
        dealokasi(P);
        cout << "Data dengan kode buku " << hapus.kodeBuku << " berhasil dihapus." << endl;
    }

    cout << "DATA LIST 1" << endl;
    printInfo(L);

    return 0;
}
```

### Output Unguided 3 :

### Output Singlylist
![Output Unguided]!(foto/laprak_unguided.png)

Program ini menyimpan data kendaraan (nomor polisi, warna, tahun) dalam doubly linked list. doublylist.h berisi struktur data dan daftar fungsi, doublylist.cpp berisi isi fungsinya (termasuk deleteElm yang menghapus berdasarkan nopol dan memberi tahu berhasil atau tidak lewat status), dan main.cpp menjalankan alurnya: input data dengan pengecekan nopol ganda, mencari satu kendaraan, lalu menghapus satu kendaraan. Di doublylist.cpp saya menambah P = Nil pada dealokasi dan pada kasus list kosong, supaya pointer tidak berisi nilai acak.

## Kesimpulan

Berdasarkan praktikum yang telah dilakukan, doubly linked list terbukti sebagai struktur data yang fleksibel karena setiap node memiliki pointer next dan prev sehingga dapat ditelusuri dua arah. Implementasi ADT dengan memisahkan file header, implementasi, dan program utama membuat program lebih terstruktur. Operasi insertLast dengan pengecekan duplikasi menggunakan findElm berhasil menambahkan data tanpa kode ganda, searching dengan linear search berhasil menemukan data yang dicari, dan operasi deleteFirst, deleteLast, serta deleteAfter berhasil menghapus data di awal, akhir, maupun tengah list dengan menyambungkan kembali pointer di sekitarnya. Dibanding singly linked list, doubly linked list lebih mudah untuk penghapusan data, dengan konsekuensi memori yang sedikit lebih besar karena menyimpan satu pointer tambahan.

## Referensi
[1] A. Wijoyo, L. A. Prayudi, M. Fiqih, R. D. Santoso, R. T. S. Putra, T. Arifin, dan A. Farhan, "Penggunaan Algoritma Doubly Linked List Untuk Insertion Dan Deletion," JRIIN: Jurnal Riset Informatika dan Inovasi, vol. 1, no. 12, hlm. 1329–1331, 2024. [Online]. Tersedia: https://jurnalmahasiswa.com/index.php/jriin/article/view/1282
