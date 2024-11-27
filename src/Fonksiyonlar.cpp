/** 
* @file Fonksiyonlar.cpp
* @description Programin calismasi icin gerekli fonksiyonlari icerir
* @course 1. Ogretim C grubu
* @assignment 1. Odev
* @date 15-11-2024
* @author Emir Caglar Demirci caglar.demirci@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <fstream>

#include "../include/BagliListe.hpp"
#include "../include/Fonksiyonlar.hpp"
#include "../include/Dugum.hpp"
using namespace std;

static BagliListe* liste = nullptr;
int listeNo = 0;

void Fonksiyonlar::Caprazlama(int* sayi1, int* sayi2)
{
    Dugum* bir = liste->ilk;
    Dugum* bir1;
    Dugum* iki = liste->ilk;
    Dugum* iki1;

    int kromozom1Uzunluk = 0;
    int kromozom2Uzunluk = 0;
    string kromozom1("");
    string kromozom2("");

    for(int i = 0; i < *sayi1; i++)
    {
        while(bir->veri != '_')
        {
            bir = bir->sonraki;
        }
        if(bir->veri == '_')
        {
            bir = bir->sonraki;
        }
    }
    bir1 = bir;
    cout << "Kromozom 1: ";
    while(bir1->veri != '_')
    {
        cout << bir1->veri << ' ';
        kromozom1 += bir1->veri;
        bir1 = bir1->sonraki;
        kromozom1Uzunluk++;
    }
    bir1 = bir;
    cout << endl;


    for(int i = 0; i < *sayi2; i++)
    {
        while(iki->veri != '_')
        {
            iki = iki->sonraki;
        }
        if(iki->veri == '_')
        {
            iki = iki->sonraki;
        }
    }
    iki1 = iki;
    cout << "Kromozom 2: ";
    while(iki1->veri != '_')
    {
        cout << iki1->veri << ' ';
        kromozom1 += iki1->veri;
        iki1 = iki1->sonraki;
        kromozom2Uzunluk++;
    }
    iki1 = iki;
    cout << endl;
    cout << "Olusan ve listeye eklenen kromozomlar: " << endl;

    // sayi1'in sol yarisini ekle
    for(int i = 0; i < kromozom1Uzunluk/2; i++)
    {
        cout << bir1->veri << ' ';
        liste->Ekle(bir1->veri);
        bir1 = bir1->sonraki;
    }
    // bir1 = bir;
    cout << ' ';
    // sayi2'nin sag yarisini ekle

    for(int i = 0; i < kromozom2Uzunluk/2; i++)
    {
        iki1 = iki1->sonraki;
    }

    if(kromozom2Uzunluk % 2 == 0)
    {
        for(int i = kromozom2Uzunluk/2; i < kromozom2Uzunluk; i++)
        {
            cout << iki1->veri << ' ';
            liste->Ekle(iki1->veri);
            iki1 = iki1->sonraki;
        }
        iki1 = iki;
    } else {
        for(int i = kromozom2Uzunluk/2 + 1; i < kromozom2Uzunluk; i++)
        {
            cout << iki1->veri << ' ';
            liste->Ekle(iki1->veri);
            iki1 = iki1->sonraki;
        }
        iki1 = iki;        
    }
    liste->Ekle('_');
    cout << endl;

    // sayi1'in sag yarisini ekle
    if(kromozom1Uzunluk % 2 == 0)
    {
        for(int i = kromozom1Uzunluk/2; i < kromozom1Uzunluk; i++)
        {
            cout << bir1->veri << ' ';
            liste->Ekle(bir1->veri);
            bir1 = bir1->sonraki;
        }
        // bir1 = bir;
    } else {
        for(int i = kromozom1Uzunluk/2 + 1; i < kromozom1Uzunluk; i++)
        {
            cout << bir1->veri << ' ';
            liste->Ekle(bir1->veri);
            bir1 = bir1->sonraki;
        }
        // bir1 = bir;  
    }
    // sayi2'nin sol yarisini ekle
    for(int i = 0; i < kromozom2Uzunluk/2; i++)
    {
        cout << iki1->veri << ' ';
        liste->Ekle(iki1->veri);
        iki1 = iki1->sonraki;
    }
    cout << endl;      
    iki1 = iki;
    cout << ' ';

    liste->Ekle('_');
}

void Fonksiyonlar::Mutasyon(int* sayi1, int* sayi2)
{
    Dugum* gec = liste->ilk;
    Dugum* gec2;
    Dugum* gec3;

    for(int i = 0; i < *sayi1; i++)
    {
        while(gec->veri != '_') {
            gec = gec->sonraki;
        }
        if(gec->veri == ('_')) {
            gec = gec->sonraki;
        }
    }

    gec2 = gec;
    gec3 = gec;
    cout << "Mutasyona ugrayacak kromozom: \t";
    while(gec2->veri != '_' && gec3->sonraki != nullptr)
    {
        cout << gec2->veri << ' ';
        gec2 = gec2->sonraki;
    }
    cout << endl << endl;

    for(int i = 0; i < *sayi2; i++)
    {
        gec = gec->sonraki;
    }

    gec->veri = 'X';

    cout << "Mutasyondan sonra: \t\t";
    while(gec3->veri != '_' && gec3->sonraki != nullptr)
    {
        cout << gec3->veri << ' ';
        gec3 = gec3->sonraki;
    }    
    cout << endl;
}

void Fonksiyonlar::EkranaYaz() {
    if (liste == nullptr || liste->ilk == nullptr) {
        cout << "Liste bos!" << endl;
        return;
    }

    Dugum* gec = liste->ilk;

    while (gec != nullptr) {
        // delimiter gorursen atla
        if (gec->veri == '_') {
            gec = gec->sonraki;
            continue;
        }

        Dugum* bas = gec;
        Dugum* son = nullptr;

        // kromozomun sonunu bulmak icin sona git
        while (gec != nullptr && gec->veri != '_') {
            son = gec;
            gec = gec->sonraki;
        }

        // sondan geri dogru hareket et
        char ilkGen = bas->veri;
        char secilenGen = ilkGen;
        while (son != nullptr && son->onceki != nullptr && son != bas->onceki) {
            if (son->veri < ilkGen) {
                secilenGen = son->veri;
                break;
            }
            son = son->onceki;
        }

        cout << secilenGen << ' ';
    }

    cout << endl;
}


void Fonksiyonlar::OtoIslem()
{   
    ifstream dosya(ISLEMLER_ADRES);

    if(dosya.is_open())
    {
        string satir;

        while(getline(dosya, satir))
        {
            if(satir[0] == 'C')
            {
                istringstream ss(satir);
                string komut;
                int sayi1, sayi2;
                ss >> komut >> sayi1 >> sayi2;

                Caprazlama(&sayi1, &sayi2);
            }
            if(satir[0] == 'M')
            {
                istringstream ss(satir);
                string komut;
                int sayi1, sayi2;
                ss >> komut >> sayi1 >> sayi2;

                Mutasyon(&sayi1, &sayi2);
            }
        }
    }
}


void Fonksiyonlar::Program() {


   int secim;
    do {
        int sayi1 = 0;
        int sayi2 = 0;

        cout << endl << "Bir fonksiyon secin: " << endl;
        cout << "1- Caprazlama" << endl;
        cout << "2- Mutasyon" << endl;
        cout << "3- Otomatik Islemler" << endl;
        cout << "4- Ekrana Yaz" << endl;
        cout << "5- Cikis" << endl;

        cin >> secim;

        switch (secim) {
            case 1:

                cout << endl << "Sol yarisi istenen kromozom sirasi: ";
                cin >> sayi1;
                cout << endl << "Sag yarisi istenen kromozom sirasi: ";
                cin >> sayi2;
                cout << endl;
                Fonksiyonlar::Caprazlama(&sayi1, &sayi2);
                break;

            case 2:
                cout << endl << "Mutasyona ugrayacak kromozom: ";
                cin >> sayi1;
                cout << endl << "Kromozomdaki DNA'nin sirasi: ";
                cin >> sayi2;
                cout << endl;
                Fonksiyonlar::Mutasyon(&sayi1, &sayi2);
                break;

            case 3:
                Fonksiyonlar::OtoIslem();
                cout << "\nOtomatik Islemler Gerceklestirildi..." << endl;
                break;

            case 4:
                Fonksiyonlar::EkranaYaz();
                break;

            case 5:
                cout << "Programdan cikiliyor..." << endl;
                break;

            default:
                cout << "Gecersiz secim, tekrar deneyin." << endl;
        }

    } while (secim != 5);
}


int Fonksiyonlar::Cikis() {
    if (liste != nullptr) {
        delete liste;
        liste = nullptr;
    }
    cout << "Programdan cikiliyor..." << endl;
    return 0;
}
void Fonksiyonlar::DNA_Oku() {

    
    if (liste == nullptr) {
        liste = new BagliListe();
    }
    ifstream dosya(DNA_ADRES);
    if (dosya.is_open()) {
        std::cout << "Dosya basariyla acildi!" << std::endl;
        string satir;
        while (getline(dosya, satir)) {
            if (satir.find_first_not_of(' ') != string::npos) {
                listeNo++;
                for (char harf : satir) {
                    if (harf != ' ') {
                        liste->Ekle(harf); 
                    }
                }
                liste->Ekle('_');
            }
        }
        dosya.close();
    } else {
        cerr << "Dosya acilamadi: " << DNA_ADRES << endl;
    }

}
