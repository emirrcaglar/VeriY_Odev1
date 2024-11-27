/** 
* @file Dugum.hpp
* @description Dugum sinifinin header dosyasidir
* @course 1. Ogretim C grubu
* @assignment 1. Odev
* @date 06-11-2024
* @author Emir Caglar Demirci caglar.demirci@ogr.sakarya.edu.tr
*/

#ifndef DUGUM_HPP
#define DUGUM_HPP

#include <iostream>
using namespace std;

class Dugum
{
public:
    char veri;
    Dugum* sonraki;
    Dugum* onceki;

    Dugum(char veri);
};

#endif
