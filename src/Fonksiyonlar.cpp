#include <iostream>
#include <fstream>
#include "../include/BagliListe.hpp"
#include "../include/Fonksiyonlar.hpp"
using namespace std;
string DNA_ADRES = "Dna.txt";

void Fonksiyonlar::Caprazlama()
{
    ifstream dosya(DNA_ADRES);
    if(dosya.is_open()) 
    {
        int sayi1 = 0;
        int sayi2 = 0;
        string satir;

        cout << "sayi gir" << endl;
        cin >> sayi1;
        cout << "sayi gir" << endl;
        cin >> sayi2;

        int listeNo = 0;
        while(getline(dosya, satir))
        {
            BagliListe* liste = new BagliListe();
            for(char i : satir) {
                liste->Ekle(i);
            }
            listeNo++;
            if(sayi1 == listeNo - 1){
                cout << endl << "Kromozom " << sayi1 << ": " <<*liste << endl;
            }
            if(sayi2 == listeNo - 1){
                cout << endl << "Kromozom " << sayi2 << ": " << *liste << endl;
            }
        }
    }else { cerr << "Dosya acilamadi: " << DNA_ADRES << endl;}
    dosya.close();
}
void Fonksiyonlar::Mutasyon()
{
    ifstream dosya(DNA_ADRES);
    if(dosya.is_open())
    {
        string satir;
        int listeNo = 0;
        int sayi1 = 0;
        int sira = 0;

        cout << "sayilari girin: " << endl;
        cin >> sayi1;
        cin >> sira;

        while(getline(dosya, satir))
        {
            // Liste olustur ve okunan harfleri dugumlere ekle
            BagliListe* liste = new BagliListe();
            for(char i : satir) {
                if(i!=' '){ 
                liste->Ekle(i);
                }
            }
            listeNo++; // Liste sayisi
            if(sayi1 == listeNo - 1) {
                cout << endl << "Kromozom " << sayi1 << ": " <<*liste << endl;
                cout << "\t\t|" << endl << "\t\t|" << endl << "\t\tv" << endl;
                liste->xYap(sira);
                cout << endl << "Kromozom " << sayi1 << ": " <<*liste << endl;
            } else { cout << "Liste no: " <<listeNo << endl; cerr << "Satir bulunamadi..." << endl; break;}
        }
    }else { cerr << "Dosya acilamadi: " << DNA_ADRES << endl;}
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
