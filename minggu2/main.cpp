#include <iostream>
#include "kepala.h"

using namespace std;

int main() {
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "Rata-rata: " << rata2(mhs) << endl;
    
    return 0;
}