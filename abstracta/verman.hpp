//
//  verman.hpp
//  abstracta
//
//  Created by alonso paucar ugarte on 9/9/19.
//  Copyright © 2019 alonso paucar ugarte. All rights reserved.
//

#ifndef verman_hpp
#define verman_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "/Users/alonsopaucarugarte/Desktop/abstracta/abstracta/euclides.h"

class verman{
public:
    std::string cero="00";
    std::string uno="11";
    std::string cerouno="01";
    std::string mensaje,mensaje_cifrado,c;
    std::string binario(int);
    verman(std::string,std::string);
    std::string cifrado();
    int num_cifrado(std::string);
    int potencia(int ,int );
    int numeros(std::string);
    std::string decifrado();
    std::string fun_xor(std::string,std::string);
private:
    std::string alfabeto = "abcdefghijklmnopqrstuvwxyz";
    std::string clave;
    int tam=int(clave.length());
};

#endif /* verman_hpp */
