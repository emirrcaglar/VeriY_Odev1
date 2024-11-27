/** 
* @file Dugum.cpp
* @description Dugum sinif govdesini bulundurur
* @course 1. Ogretim C grubu
* @assignment 1. Odev
* @date 06-11-2024
* @author Emir Caglar Demirci caglar.demirci@ogr.sakarya.edu.tr
*/

#include "Dugum.hpp"

Dugum::Dugum(char veri)
{
    this->veri = veri;
    sonraki = nullptr;
    onceki = nullptr;
}
