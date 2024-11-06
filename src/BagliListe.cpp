#include "BagliListe.hpp"

BagliListe::BagliListe()
{
    ilk = son = 0;
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
    }
}

void BagliListe::Ekle(char veri)
{
    Dugum* yeni = new Dugum(veri); 
    if(ilk == nullptr) {
        ilk = yeni;
    } else {
        son->sonraki = yeni;
    }
    son = yeni;
    dugumSayisi++;
}

void BagliListe::Yazdir()
{
    cout << *this;
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
    return os<<endl;
}

// Mutasyon sirasinda X e cevir
void BagliListe::xYap(int a)
{
    Dugum* gec = ilk;
    if(a == 0) { ilk->veri = 'X'; }
    for(int i = 0; i < a-1; i++){
        if(gec->sonraki->sonraki != 0){
            gec = gec->sonraki;
        }
    }
    gec->sonraki->veri = 'X';
}

void BagliListe::ilkYari()
{
    
}

void BagliListe::sonYari()
{

}
