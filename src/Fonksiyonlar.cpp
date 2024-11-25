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
    cout << "LISTE NO: " << listeNo << endl;

    Dugum* gec = liste->ilk;
    Dugum* gec2;
    Dugum* gec3;

    if(*sayi1 < *sayi2)
    {
        for(int i = 0; i < *sayi1; i++)
        {
            // cout << "SOL SIRA: " << i << endl;

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
        while(gec->veri != '_' && gec->sonraki != nullptr) {
            cout << gec->veri << ' ';
            gec = gec->sonraki;
            solListeUzunluk++;
        }
        // cout << "\nSOL LISTE YARIM: " << endl;
        for(int i = 0; i < solListeUzunluk / 2; i++){
            cout << gec2->veri << ' ';
            liste->Ekle(gec2->veri);
            gec2 = gec2->sonraki;
        }

        for(int i = *sayi1; i < *sayi2; i++)
        {
            // cout << "\nSAG SIRA: " << i << endl;
            
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
        while(gec->veri != '_' && gec->sonraki != nullptr) {
            cout << gec->veri << ' ';
            gec = gec->sonraki;
            sagListeUzunluk++;
        }
        // cout << "\nSAG LISTE UZUNLUK: " << sagListeUzunluk << endl;
        // cout << "\nSAG LISTE YARIM: " << endl;
        for(int i = 0; i < sagListeUzunluk; i++){
            if(i > sagListeUzunluk/2)
            {
                cout << gec2->veri << ' ';
                liste->Ekle(gec2->veri);
            }
            gec2 = gec2->sonraki;
        }
        liste->Ekle('_');
    }

    if(*sayi1 > *sayi2)
    {
        for(int i = 0; i < *sayi2; i++)
        {
            // cout << "SAG SIRA: " << i << endl;

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
        while(gec->veri != '_' && gec->sonraki != nullptr) {
            cout << gec->veri << ' ';
            gec = gec->sonraki;
            sagListeUzunluk++;
        }
        // cout << "SAG LISTE UZUNLUK: " << sagListeUzunluk << endl;
        // cout << "\nSAG LISTE YARIM: " << endl;
        for(int i = 0; i < sagListeUzunluk; i++){
            if(i > sagListeUzunluk/2)
            {
                cout << gec2->veri << ' ';
                liste->Ekle(gec2->veri);
            }
            gec2 = gec2->sonraki;
        }

        for(int i = *sayi2; i < *sayi1; i++)
        {
            // cout << "\nSOL SIRA: " << i << endl;
            
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
        while(gec->veri != '_' && gec->sonraki != nullptr) {
            cout << gec->veri << ' ';
            gec = gec->sonraki;
            solListeUzunluk++;
        }
        for(int i = 0; i < solListeUzunluk / 2; i++){
            cout << gec2->veri << ' ';
            liste->Ekle(gec2->veri);
            gec2 = gec2->sonraki;
        }
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
        // cout << "AYNI SATIRLAR: \n";
        while(gec->veri != '_' && gec->sonraki != nullptr) {
            gec = gec->sonraki;
            ListeUzunluk++;
        }
        for(int i = 0; i < ListeUzunluk / 2; i++){
            cout << gec2->veri << ' ';
            liste->Ekle(gec2->veri);
            gec2 = gec2->sonraki;
        }       
        for(int i = 0; i < ListeUzunluk / 2; i++){
            cout << gec3->veri << ' ';
            liste->Ekle(gec3->veri);
            gec3 = gec3->sonraki;
        }      
        liste->Ekle('_');
    }
   cout << *liste;

}

void Fonksiyonlar::Mutasyon(int* sayi1, int* sayi2)
{
    ifstream dosya(DNA_ADRES);
    ofstream ciktiDosya(DNA_ADRES, ios::app);
    if(dosya.is_open())
    {
        string satir;
        int listeNo = 0;

        bool bulundu = false;
        while(getline(dosya, satir))
        {

            if (satir.find_first_not_of(' ') == string::npos) {
                continue;
            }
            
            BagliListe* liste = new BagliListe();
            listeNo++;
            
            for(char i : satir) {
                if(i != ' ') { 
                    liste->Ekle(i);
                }
            }
            
            if(*sayi1 == listeNo-1) {
                bulundu = true; 

                cout << endl << "[M]ESKI: " <<
                *liste << endl;
                cout << "\t|" << endl << "\t| **MUTASYON**" << endl << "\tv" << endl;

                BagliListe* xListe = liste->xYap(*sayi2);
                
                // cout << *xListe << endl;
                // ciktiDosya << xListe;
                if (xListe) {
                    cout << "[M]YENI: " << *xListe << endl;
                    // ciktiDosya << endl << *xListe << endl;
                    delete xListe;
                }                
            }
            // delete liste;
        }

        if (!bulundu) {
            cerr << "Satir bulunamadi: " << *sayi1 << endl;
        }
    }
    else {
        cerr << "Dosya acilamadi: " << DNA_ADRES << endl;
    }
    ciktiDosya.close();
    dosya.close();
}

void Fonksiyonlar::EkranaYaz()
{
    ifstream dosya(DNA_ADRES);
    if(dosya.is_open()) {
        string satir;
        int listeNo = 0;
        while(getline(dosya, satir)) 
        {

            if (satir.find_first_not_of(' ') == string::npos) {
                continue;
            }

            BagliListe* liste = new BagliListe();
            for(char harf : satir){
                liste->Ekle(harf);
            }
            cout << "Kromozom " << listeNo << "\t: " <<*liste << endl;
            // liste->Yazdir();
            listeNo++;
        liste->~BagliListe();
        }
    } else { cerr << "Dosya acilamadi: " << DNA_ADRES << endl; }
    dosya.close();
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
                cout << "SATIR: " << satir << endl;
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
