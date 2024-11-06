#include <iostream>
#include <string>
#include "../include/BagliListe.hpp"
#include "../include/Fonksiyonlar.hpp"
using namespace std;

int main()
{   
    
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
        case 1: Fonksiyonlar::Caprazlama();
        break;
        case 2: Fonksiyonlar::Mutasyon();
        break;
        case 3: Fonksiyonlar::OtoIslem();
        break;
        case 4: Fonksiyonlar::EkranaYaz();
        break;
        case 5:  return 0;
    }
    
    return 0;
}
