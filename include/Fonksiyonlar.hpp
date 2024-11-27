/** 
* @file Fonksiyonlar.hpp
* @description Programin calismasini saglayan Fonksiyonlarin header dosyasidir
* @course 1. Ogretim C grubu
* @assignment 1. Odev
* @date 15-11-2024
* @author Emir Caglar Demirci caglar.demirci@ogr.sakarya.edu.tr
*/

#ifndef FONKSIYONLAR_HPP
#define FONKSIYONLAR_HPP

#define DNA_ADRES "Dna.txt"
#define ISLEMLER_ADRES "OtoIslemler.txt"

class BagliListe;

class Fonksiyonlar {
private:
    BagliListe* liste;
    int listeNo;

public:
    Fonksiyonlar(); 
    ~Fonksiyonlar();

    void DNA_Oku();
    void Caprazlama(int* sayi1, int* sayi2);
    void Mutasyon(int* sayi1, int* sayi2);
    void EkranaYaz();
    void OtoIslem();
    void Program();
    int Cikis();
};

#endif