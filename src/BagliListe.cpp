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
    }
}

void BagliListe::Ekle(char veri)
{
    Dugum* yeni = new Dugum(veri); 
    if(ilk == 0) {
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
    os << "ilk pointer: " << gec << endl;  // Debugging output

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

// Mutasyon sirasinda X e cevir
BagliListe* BagliListe::xYap(int sira)
{
    BagliListe* xListe = new BagliListe();
    Dugum* gec = ilk;

    // Handle the case where sira is 0
    if (sira == 0) { 
        ilk->veri = 'X'; 
        return xListe;
    }

    // Handle the case where sira is 1
    if (sira == 1) { 
        ilk->sonraki->veri = 'X'; 
        return xListe;
    }
    if (sira > 1)
    {
        // Traverse the list until the correct position (sira-1)
        for (int i = 0; i < sira - 1; i++) {
            if (gec->sonraki != 0) {
                xListe->Ekle(gec->veri);
                gec = gec->sonraki;
            } else {
                // If we reached the end, break the loop to avoid null dereferencing
                break;
            }
        }
        // Set the 'X' at the sira-th position
        if (gec && gec->sonraki != 0) {
            gec->sonraki->veri = 'X';
        }

        // Add the remaining nodes to xListe
        while (gec && gec->sonraki != 0) {
            xListe->Ekle(gec->veri);
            gec = gec->sonraki;
        }
    }

    return xListe;
}


BagliListe* BagliListe::ListeSol(int x)
{
    
    if(x == 0) { return nullptr; }
    Dugum* gec = ilk;
    BagliListe* listeSol = new BagliListe();
    for(int i = 0; i < x / 2; i++)
    {
        listeSol->Ekle(gec->veri);
        gec = gec->sonraki;
    }
    return listeSol;  // Free allocated memory
}

BagliListe* BagliListe::ListeSag(int x)
{
    if(x == 0) { return nullptr; }
    Dugum* gec = ilk;  // Start from `ilk` and move up to x/2 + 1
    BagliListe* listeSag = new BagliListe();
    if(x % 2 == 0)
    {
        for(int i = 0; i < x; i++)
        {
            if(i >= x / 2) 
            {
                listeSag->Ekle(gec->veri);
            }
            gec = gec->sonraki;
        }
    } else {
        for(int i = 0; i < x; i++)
        {
            if(i >= x / 2 + 1) 
            {
                listeSag->Ekle(gec->veri);
            }
            gec = gec->sonraki;
        }
    }
    return listeSag;  // Free allocated memory
}

