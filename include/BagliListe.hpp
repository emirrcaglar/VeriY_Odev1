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

    void xYap(int);
    int listeUzunluk();

    void ilkYari();
    void sonYari();

    friend ostream& operator<<(ostream& os,BagliListe& liste);

};

#endif