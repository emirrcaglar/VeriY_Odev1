/** 
* @file Fonksiyonlar.hpp
* @description Programin calismasini saglayan Fonksiyonlarin header dosyasidir
* @course 1. Ogretim C grubu
* @assignment 1. Odev
* @date 15-11-2024
* @author Emir Caglar Demirci caglar.demirci@ogr.sakarya.edu.tr
*/


#ifndef FONKSIYONLAR_HPP
#define FONKSIYONLAR_HPP
#include "BagliListe.hpp"
#include "Dugum.hpp"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
const string DNA_ADRES = "Dna.txt";
const string ISLEMLER_ADRES = "OtoIslemler.txt";


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