#include "mahasiswa.h"

float hitungNilaiAkhir(Mahasiswa m) {
    return 0.3 * m.uts + 0.4 * m.uas + 0.3 * m.tugas;
}

void inputMahasiswa(Mahasiswa &m) {
    cout << "Nama: "; cin >> ws; getline(cin, m.nama);
    cout << "NIM: "; cin >> m.nim;
    cout << "UTS, UAS, Tugas: "; cin >> m.uts >> m.uas >> m.tugas; //pake spasi biar bisa input
    m.nilai_akhir = hitungNilaiAkhir(m);
}

void tampilMahasiswa(Mahasiswa m) {
    cout << m.nim << " | " << m.nama << " | NA: " << m.nilai_akhir << endl;
}