/** 
* @file BagliListe.cpp
* @description Bagli Liste fonksiyon govdelerini icerir
* @course 1. Ogretim C grubu
* @assignment 1. Odev
* @date 06-11-2024
* @author Emir Caglar Demirci caglar.demirci@ogr.sakarya.edu.tr
*/

#include "BagliListe.hpp"

BagliListe::BagliListe()
{
    ilk = son = nullptr;
    dugumSayisi = 0;
}
BagliListe::~BagliListe()
{
    Dugum* gec = ilk;
    while(gec!=0)
    {
        Dugum* sil = gec;
        gec = gec->sonraki;
        delete sil;
        sil = nullptr;
    }
}

void BagliListe::Ekle(char veri)
{
    Dugum* yeni = new Dugum(veri); 
    if(ilk == 0) {
        ilk = yeni;
    } else {
        yeni->onceki = son;
        son->sonraki = yeni;
    }
    son = yeni;
    dugumSayisi++;
}

ostream& operator<<(ostream& os,BagliListe& liste)
{
    Dugum* gec = liste.ilk;

    if(gec==0)
    {
        return os<<"Liste Bos"<<endl;
    }
    for(int i=0;i<liste.dugumSayisi;i++)
    {
        os<<gec->veri<<" ";
        gec = gec->sonraki;
    }
    return os;
}
