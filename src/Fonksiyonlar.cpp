#include <iostream>
#include <fstream>
#include "../include/BagliListe.hpp"
#include "../include/Fonksiyonlar.hpp"
using namespace std;
string DNA_ADRES = "Dna.txt";

void Fonksiyonlar::Caprazlama()
{
    ifstream dosya(DNA_ADRES);
    ofstream ciktiDosya(DNA_ADRES, ios::app);  // Open output file
    if (!ciktiDosya.is_open()) {
        cerr << "Dosya acilamadi: output.txt" << endl;
        return;
    }

    if(dosya.is_open()) 
    {
        int sayi1 = 0;
        int sayi2 = 0;
        string satir;

        cout << "sol gir" << endl;
        cin >> sayi1;
        cout << "sag gir" << endl;
        cin >> sayi2;

        int listeNo = 0;
        BagliListe* solListe = nullptr;
        BagliListe* sagListe = nullptr;

        while(getline(dosya, satir))
        {
            BagliListe* liste = new BagliListe();
            for(char i : satir) {
                if(i != ' ') { 
                    liste->Ekle(i);
                }
            }
            listeNo++;
            if(sayi1 == listeNo - 1){
                solListe = liste->ListeSol(liste->dugumSayisi);
            }
            if(sayi2 == listeNo - 1){
                sagListe = liste->ListeSag(liste->dugumSayisi);
            }

            delete liste;
        }
        if (solListe && sagListe) {
            cout << *solListe << " " << *sagListe << endl;
            ciktiDosya << endl << *solListe << " " << *sagListe << endl;  // Write both in the same line
        }
        delete solListe;
        delete sagListe;
    } else { 
        cerr << "Dosya acilamadi: " << DNA_ADRES << endl;
    }

    dosya.close();
    ciktiDosya.close();
}

void Fonksiyonlar::Mutasyon()
{
    ifstream dosya(DNA_ADRES);
    ofstream ciktiDosya(DNA_ADRES, ios::app);
    if(dosya.is_open())
    {
        string satir;
        int listeNo = 0;
        int satir1 = 0;
        int sira = 0;

        cout << "Satir1 girin: ";
        cin >> satir1;
        cout << "Sira girin: ";
        cin >> sira;

        bool bulundu = false; // Flag to track if the target line was found
        while(getline(dosya, satir))
        {
            BagliListe* liste = new BagliListe();
            listeNo++; // Increment list number
            
            for(char i : satir) {
                if(i != ' ') { 
                    liste->Ekle(i);
                }
            }
            if(satir1 == listeNo-1) {
                bulundu = true; // Mark that the line was found

                cout << endl << *liste << endl << endl;
                cout << "\t|" << endl << "\t|" << endl << "\tv" << endl << endl;

                BagliListe* xListe = liste->xYap(sira); // Perform mutation at the specified position
                
                cout << *xListe << endl;
                // ciktiDosya << xListe;
                if (xListe) {
                    cout << *xListe << endl;
                    ciktiDosya << endl << *xListe << endl;
                    delete xListe;
                }                
            }

            delete liste;
        }

        if (!bulundu) {
            cerr << "Satir bulunamadi: " << satir1 << endl;
        }
    }
    else {
        cerr << "Dosya acilamadi: " << DNA_ADRES << endl;
    }
    ciktiDosya.close();
    dosya.close();
}

void Fonksiyonlar::OtoIslem()
{
    cout << "OTOISLEM";
}

void Fonksiyonlar::EkranaYaz()
{
    ifstream dosya(DNA_ADRES);
    if(dosya.is_open()) {
        string satir;
        int listeNo = 0;
        while(getline(dosya, satir)) 
        {
            BagliListe* liste = new BagliListe();
            for(char harf : satir){
                liste->Ekle(harf);
            }
            cout << "Kromozom " << listeNo << "\t: " <<*liste;
            // liste->Yazdir();
            listeNo++;
        liste->~BagliListe();
        }
    } else { cerr << "Dosya acilamadi: " << DNA_ADRES << endl; }
    dosya.close();
}
