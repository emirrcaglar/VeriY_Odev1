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
    // cout << "LISTE NO: " << listeNo << endl;

    Dugum* gec = liste->ilk;
    Dugum* gec2;
    Dugum* gec3;
    string sagYari("");
    string solYari("");

    if(*sayi1 < *sayi2)
    {
        for(int i = 0; i < *sayi1; i++)
        {
            while(gec->veri != '_') { 
                gec = gec->sonraki; 
            }
            if(gec->veri == '_')
            {
                gec = gec->sonraki;
            }
        }
        gec2 = gec;
        int solListeUzunluk = 0;
        cout << "\nSOL YARISI ALINACAK KROMOZOM: \n";
        while(gec->veri != '_' && gec->sonraki != nullptr) {
            cout << gec->veri << ' ';
            gec = gec->sonraki;
            solListeUzunluk++;
        }
        cout << "\nAlinacak kesit: \n";
        for(int i = 0; i < solListeUzunluk / 2; i++){
            cout << gec2->veri << ' ';
            solYari += gec2->veri;
            solYari += ' ';

            liste->Ekle(gec2->veri);
            gec2 = gec2->sonraki;
        }

        for(int i = *sayi1; i < *sayi2; i++)
        {
            
            while(gec->veri != '_') { 
                gec = gec->sonraki; 
            }
            if(gec->veri == '_')
            {
                gec = gec->sonraki;
            }
        }
        gec2 = gec;
        int sagListeUzunluk = 0;

        cout << "\n\nSAG YARISI ALINACAK KROMOZOM\n";
        while(gec->veri != '_' && gec->sonraki != nullptr) {
            cout << gec->veri << ' ';
            gec = gec->sonraki;
            sagListeUzunluk++;
        }
        // cout << "\nSAG LISTE UZUNLUK: " << sagListeUzunluk << endl;
        cout << "\nAlinacak kesit: \n";
        for(int i = 0; i < sagListeUzunluk; i++){
            if(i > sagListeUzunluk/2)
            {
                cout << gec2->veri << ' ';
                sagYari += gec2->veri;
                sagYari += ' ';
                liste->Ekle(gec2->veri);
            }
            gec2 = gec2->sonraki;
        }
        cout << "\n\nCaprazlama sonucunda olusan kromozom: \n";
        cout << solYari << sagYari << endl; 
        liste->Ekle('_');
    }

    if(*sayi1 > *sayi2)
    {
        for(int i = 0; i < *sayi2; i++)
        {

            while(gec->veri != '_') { 
                gec = gec->sonraki; 
            }
            if(gec->veri == '_')
            {
                gec = gec->sonraki;
            }
        }
        gec2 = gec;
        int sagListeUzunluk = 0;
        cout << "\nSAG YARISI ALINACAK KROMOZOM: \n";
        while(gec->veri != '_' && gec->sonraki != nullptr) {
            cout << gec->veri << ' ';
            gec = gec->sonraki;
            sagListeUzunluk++;
        }
        // cout << "SAG LISTE UZUNLUK: " << sagListeUzunluk << endl;
        cout << "\nAlinacak kesit: \n";
        for(int i = 0; i < sagListeUzunluk; i++){
            if(i > sagListeUzunluk/2)
            {
                cout << gec2->veri << ' ';
                sagYari += gec2->veri;
                sagYari += ' ';
                liste->Ekle(gec2->veri);
            }
            gec2 = gec2->sonraki;
        }

        for(int i = *sayi2; i < *sayi1; i++)
        {
            
            while(gec->veri != '_') { 
                gec = gec->sonraki; 
            }
            if(gec->veri == '_')
            {
                gec = gec->sonraki;
            }
        }
        gec2 = gec;
        int solListeUzunluk = 0;
        cout << "\nSOL YARISI ALINACAK KROMOZOM: \n";
        while(gec->veri != '_' && gec->sonraki != nullptr) {
            cout << gec->veri << ' ';
            gec = gec->sonraki;
            solListeUzunluk++;
        }
        cout << "\nAlinacak kesit: \n";
        for(int i = 0; i < solListeUzunluk / 2; i++){
            cout << gec2->veri << ' ';
            liste->Ekle(gec2->veri);
            solYari += gec2->veri;
            solYari += ' ';        
            gec2 = gec2->sonraki;
        }
        cout << "\n\nCaprazlama sonucunda olusan kromozom: \n";
        cout << solYari << sagYari << endl; 
        liste->Ekle('_');
    }

    if(*sayi1 == *sayi2)
    {
        for(int i = 0; i < *sayi1; i++)
        {
            while(gec->veri != '_') { 
                gec = gec->sonraki; 
            }
            if(gec->veri == '_')
            {
                gec = gec->sonraki;
            }
        }    
        gec2 = gec;
        gec3 = gec;
        int ListeUzunluk = 0;
        cout << "KROMOZOMLAR AYNI: \n";
        while(gec->veri != '_' && gec->sonraki != nullptr) {
            cout << gec->veri << ' ';
            gec = gec->sonraki;
            ListeUzunluk++;
        }
        cout << endl;
        for(int i = 0; i < ListeUzunluk / 2; i++){
            liste->Ekle(gec2->veri);
            solYari += gec2->veri;
            solYari += ' ';
            gec2 = gec2->sonraki;
        }   
        cout << endl;    
        for(int i = 0; i < ListeUzunluk / 2; i++){
            cout << gec3->veri << ' ';
            liste->Ekle(gec3->veri);
            gec3 = gec3->sonraki;
        }      
        cout << "\n\nCaprazlama sonucunda olusan kromozom: \n";
        cout << solYari << solYari << endl;         
        liste->Ekle('_');
    }
   // cout << *liste;

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

void Fonksiyonlar::EkranaYaz()
{
    Dugum* gec = liste->ilk;
    char enKucuk = gec->veri;

    while(gec->veri != '_' && gec->sonraki != nullptr)
    {
        // cout << gec->veri << ' ';
        if(gec->veri < enKucuk)
        {
            enKucuk = gec->veri;
        }
        gec = gec->sonraki;

        if(gec->veri == '_')
        {
            cout << enKucuk << endl;
            gec = gec->sonraki;
            enKucuk = gec->veri;
        }
    }
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
                /*
                cout << endl << "Sol yarisi istenen kromozom sirasi: ";
                cin >> sayi1;
                cout << endl << "Sag yarisi istenen kromozom sirasi: ";
                cin >> sayi2;
                cout << endl;
                Fonksiyonlar::Caprazlama(&sayi1, &sayi2);
                */

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
        string satir;
        while (getline(dosya, satir)) {
            if (satir.find_first_not_of(' ') != string::npos) { // Skip empty or whitespace-only lines
                // cout << "SATIR: " << satir << endl;
                listeNo++;
                for (char harf : satir) {
                    if (harf != ' ') {
                        liste->Ekle(harf); // Add each gene to the list
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
