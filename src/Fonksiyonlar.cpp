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

            // Check if the line is empty or contains only spaces
            if (satir.find_first_not_of(' ') == string::npos) {
                continue;  // Skip lines that are empty or contain only spaces
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
                cout << "[C]SOL: " << *liste << ' ';
            }
            if(*sayi2 == listeNo - 1){
                sagListe = liste->ListeSag(liste->dugumSayisi);
                cout << "[C]SAG: " << *liste << endl << endl;

            }

            delete liste;
        }
        if (solListe && sagListe) {
            cout << "\t**CAPRAZLAMA**" << endl << endl;
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

        bool bulundu = false; // Flag to track if the target line was found
        while(getline(dosya, satir))
        {

            // Check if the line is empty or contains only spaces
            if (satir.find_first_not_of(' ') == string::npos) {
                continue;  // Skip lines that are empty or contain only spaces
            }
            
            BagliListe* liste = new BagliListe();
            listeNo++; // Increment list number
            
            for(char i : satir) {
                if(i != ' ') { 
                    liste->Ekle(i);
                }
            }
            
            if(*sayi1 == listeNo-1) {
                bulundu = true; // Mark that the line was found

                cout << endl << "[M]ESKI: " <<
                *liste << endl;
                cout << "\t|" << endl << "\t| **MUTASYON**" << endl << "\tv" << endl;

                BagliListe* xListe = liste->xYap(*sayi2); // Perform mutation at the specified position
                
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
