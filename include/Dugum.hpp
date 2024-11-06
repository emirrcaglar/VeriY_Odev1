#ifndef DUGUM_HPP
#define DUGUM_HPP

#include <iostream>

using namespace std;

class Dugum
{
public:
    char veri;
    Dugum* sonraki;    

    Dugum (char veri);
};

#endif