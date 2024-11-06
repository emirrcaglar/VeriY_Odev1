#ifndef BAGLILISTE_HPP
#define BAGLILISTE_HPP

#include <iostream>
#include "Dugum.hpp"

using namespace std;

class BagliListe
{
private:
    Dugum* ilk;
    Dugum* son;
public:
    int dugumSayisi;
    BagliListe();
    ~BagliListe();
    
    void Ekle(char veri);
    void Yazdir();

    BagliListe* xYap(int);

    BagliListe* ListeSol(int);
    BagliListe* ListeSag(int);

    friend ostream& operator<<(ostream& os,BagliListe& liste);

};

#endif