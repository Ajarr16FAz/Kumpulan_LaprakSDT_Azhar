#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cout << "input: ";
    cin >> n;

    cout << "output:" << endl;

    for (int i = n; i >= 1; i--) {
        // Cetak spasi di awal untuk membentuk pola rata tengah/segitiga
        cout << string((n - i) * 2, ' ');

        // Angka menurun (misal: 3 2 1)
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        // Karakter Bintang
        cout << "* ";

        // Angka naik (misal: 1 2 3)
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }

    // Baris terakhir (hanya cetak bintang)
    cout << string(n * 2, ' ') << "*" << endl;

    return 0;
}