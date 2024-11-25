#include <iostream>
#include <fstream>

#include "../include/BagliListe.hpp"
#include "../include/Fonksiyonlar.hpp"
using namespace std;

void Fonksiyonlar::Caprazlama(int* sayi1, int* sayi2)
{
    ifstream dosya(DNA_ADRES);
    ofstream ciktiDosya(DNA_ADRES, ios::app);  // Open output file
    if (!ciktiDosya.is_open()) {
        cerr << "Dosya acilamadi: output.txt" << endl;
        return;
    }

    if(dosya.is_open()) 
    {
        string satir;

        int listeNo = 0;
        BagliListe* solListe = nullptr;
        BagliListe* sagListe = nullptr;

        while(getline(dosya, satir))
        {

            // Satir bos mu, ya da sadece space mi iceriyor 
            if (satir.find_first_not_of(' ') == string::npos) {
                continue;  // Bos ya da sadece space iceren satirlari atla
            }

            BagliListe* liste = new BagliListe();

            for(char i : satir) {
                if(i != ' ') { 
                    liste->Ekle(i);
                }
            }

            listeNo++;
            if(*sayi1 == listeNo - 1){
                solListe = liste->ListeSol(liste->dugumSayisi);
                cout << "[C]SOL: " << *liste << endl;
            }
            if(*sayi2 == listeNo - 1){
                sagListe = liste->ListeSag(liste->dugumSayisi);
                cout << "[C]SAG: " << *liste << endl;

            }

            delete liste;
        }
        if (solListe && sagListe) {
            cout << "\n\t**CAPRAZLAMA**\n" << endl;
            cout << "[C]YENI: "<< *solListe << ' '  << *sagListe << endl;
            // ciktiDosya << endl << *solListe << " " << *sagListe << endl;
        }
        delete solListe;
        delete sagListe;
    } else { 
        cerr << "Dosya acilamadi: " << DNA_ADRES << endl;
    }

    dosya.close();
    ciktiDosya.close();
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
            delete liste;
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


void Fonksiyonlar::Program()
{
    int sayi1 = 0;
    int sayi2 = 0;

    cout << endl << "Bir fonksiyon secin: " << endl;
    cout << "1- Caprazlama" << endl;
    cout << "2- Mutasyon" << endl;
    cout << "3- Otomatik Islemler" << endl;
    cout << "4- Ekrana Yaz" << endl;
    cout << "5- Cikis" << endl;
    int secim;
    cin >> secim;

    switch(secim)
    {          
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
        cout << endl << "Kromozomdaki DNA'nin sirasi:  ";
        cin >> sayi2;
        cout << endl;
        Fonksiyonlar::Mutasyon(&sayi1, &sayi2);

        break;
        case 3: Fonksiyonlar::OtoIslem(); 
        break;
        case 4: Fonksiyonlar::EkranaYaz();
        break;
        case 5: Fonksiyonlar::Cikis();
    }
  
}

int Fonksiyonlar::Cikis()
{
    return 0;
}