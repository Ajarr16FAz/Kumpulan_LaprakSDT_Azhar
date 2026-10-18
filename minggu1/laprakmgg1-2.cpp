#include <iostream>
#include <string>

using namespace std;

string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas"};

string terbilang(int n) {
    if (n < 12) {
        return satuan[n];
    } else if (n < 20) {
        return terbilang(n - 10) + " belas";
    } else if (n < 100) {
        return terbilang(n / 10) + " puluh " + terbilang(n % 10);
    } else if (n == 100) {
        return "seratus";
    }
    return "";
}

int main() {
    int angka;

    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    cout << "Output: ";
    if (angka == 0) {
        cout << "nol" << endl;
    } else if (angka > 0 && angka <= 100) {
        cout << terbilang(angka) << endl;
    } else {
        cout << "Angka di luar jangkauan (0-100)!" << endl;
    }

    return 0;
}