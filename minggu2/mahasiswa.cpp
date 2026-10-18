#include <iostream>
#include "kepala.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "Masukkan nim: ";
    cin >> m.nim;
    cout << "Masukkan Nilai 1: ";
    cin >> m.nilai1; 
    cout << "Masukkan Nilai 2: ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return (m.nilai1 + m.nilai2)/2;
}