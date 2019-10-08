//
//  protocolo.hpp
//  abstracta
//
//  Created by alonso paucar ugarte on 10/6/19.
//  Copyright © 2019 alonso paucar ugarte. All rights reserved.
//

#ifndef protocolo_hpp
#define protocolo_hpp
#include <stdio.h>
#include <iostream>
#include <string>
#include "/Users/alonsopaucarugarte/Desktop/abstracta/abstracta/euclides.h"
#include "enig.hpp"
#include "culebra.hpp"
#include "verman.hpp"
#include "vigenere.hpp"
#include "afin.hpp"
#include <cstdlib>
using namespace euclides;
class protocolo{
public:
    std::string me,clave_vige,c_m,pos;
    protocolo(std::string,std::string,int ,int);
    protocolo(std::string);
    void rotor(std::string,int,int);
    int filas,columnas;
    int a,b;
    std::string clave();
    std::string me_deci;
    std::string descifrado();
private:
    std::string alfabeto = "abcdefghijklmnopqrstuvwxyz";
    std::string alfa1,alfa2,alfa3;
    
};
#endif /* protocolo_hpp */
