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