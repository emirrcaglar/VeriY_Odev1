#ifndef FONKSIYONLAR_HPP
#define FONKSIYONLAR_HPP
#include "BagliListe.hpp"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
const string DNA_ADRES = "Dna.txt";
const string ISLEMLER_ADRES = "Islemler.txt";


namespace Fonksiyonlar
{

    void Caprazlama(int*, int*);
    void Mutasyon(int*, int*);

    void OtoIslem();

    void EkranaYaz();
};

#endif