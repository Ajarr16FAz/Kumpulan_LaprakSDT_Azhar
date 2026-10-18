#ifndef KEPALA_H_INCLUDED
#define KEPALA_H_INCLUDED

#include <string>

struct mahasiswa {
    std::string nim;
    float nilai1; 
    float nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif