#include "../include/Fonksiyonlar.hpp"
#include <chrono>
using namespace std::chrono;

int main()
{
    
    auto start = std::chrono::system_clock::now();

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

        cout << endl << "Sol yarisi istenen satir: ";
        cin >> sayi1;
        cout << endl << "Sag yarisi istenen satir: ";
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
        case 5:  return 0;
    }

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << elapsed.count() << '\n';
    
    return 0;
}
