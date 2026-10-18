#include "mahasiswa.h"

int main() {
    Mahasiswa mhs[10];
    int n;
    cout << "Jumlah mhs (max 10): "; cin >> n;

    for (int i = 0; i < n && i < 10; i++) {
        cout << "\nData ke-" << i + 1 << endl;
        inputMahasiswa(mhs[i]);
    }

    cout << "\n--- Hasil Data ---\n";
    for (int i = 0; i < n && i < 10; i++) {
        tampilMahasiswa(mhs[i]);
    }
    return 0;
}