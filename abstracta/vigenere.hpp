//
//  vigenere.hpp
//  abstracta
//
//  Created by alonso paucar ugarte on 9/16/19.
//  Copyright © 2019 alonso paucar ugarte. All rights reserved.
//

#ifndef vigenere_hpp
#define vigenere_hpp
#include <string>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "/Users/alonsopaucarugarte/Desktop/abstracta/abstracta/euclides.h"
const std::string alfabeto = "abcdefghijklmnopqrstuvwxyz";
class vigenere{
private:
    std::string cl;
   
public:
    std::string me;
    std::string mensaje_cifrado;
    std::string mensaje_decifrado;
    vigenere(std::string);
    vigenere(std::string,std::string);
    std::string cifrado();
    std::string decifrado();
    std::string imp_clave();
    std::string gen_clave();
    
};
#endif /* vigenere_hpp */
