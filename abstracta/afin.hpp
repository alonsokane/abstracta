//
//  afin.hpp
//  abstracta
//
//  Created by alonso paucar ugarte on 9/23/19.
//  Copyright © 2019 alonso paucar ugarte. All rights reserved.
//

#ifndef AFIN_H
#define AFIN_H
#include <string>
#include "/Users/alonsopaucarugarte/Desktop/abstracta/abstracta/euclides.h"
#include <vector>
//const std::string alfa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

using namespace euclides;
class Afin {
private:
    const std::string alfaafin = "abcdefghijklmnopqrstuvwxyz";
    int size;
    int ai;
    int inversa(int, int);

public:
    int a, b;
    std::string cifrar(std::string);
    std::string descifrar(std::string);
    Afin();
    Afin(int a, int b);
};

#endif // AFIN_H

