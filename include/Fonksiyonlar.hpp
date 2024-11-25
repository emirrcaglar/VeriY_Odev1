#ifndef FONKSIYONLAR_HPP
#define FONKSIYONLAR_HPP
#include "BagliListe.hpp"
#include "Dugum.hpp"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
const string DNA_ADRES = "BuyukDna.txt";
const string ISLEMLER_ADRES = "BuyukIslemler.txt";


namespace Fonksiyonlar
{

    void Caprazlama(int*, int*);
    void Mutasyon(int*, int*);

    void OtoIslem();

    void EkranaYaz();

    void Program();
    int Cikis();    

    void DNA_Oku();
};

#endif