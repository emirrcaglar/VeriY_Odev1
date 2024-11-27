/** 
* @file BagliListe.hpp
* @description Bagli Liste fonksiyonlarinin header dosyasidir
* @course 1. Ogretim C grubu
* @assignment 1. Odev
* @date 06-11-2024
* @author Emir Caglar Demirci caglar.demirci@ogr.sakarya.edu.tr
*/


#ifndef BAGLILISTE_HPP
#define BAGLILISTE_HPP

#include <iostream>
#include "Dugum.hpp"

using namespace std;

class BagliListe
{
private:

public:
    Dugum* ilk;
    Dugum* son;
    
    int dugumSayisi;
    BagliListe();
    ~BagliListe();
    
    void Ekle(char veri);

    friend ostream& operator<<(ostream& os,BagliListe& liste);

};

#endif