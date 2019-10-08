//
//  enig.hpp
//  abstracta
//
//  Created by alonso paucar ugarte on 9/24/19.
//  Copyright © 2019 alonso paucar ugarte. All rights reserved.
//

#ifndef enig_hpp
#define enig_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include "/Users/alonsopaucarugarte/Desktop/abstracta/abstracta/euclides.h"
using namespace euclides;
class enig{
    
public:
    std::string rotor1,rotor2,rotor3,r1,r2,r3;
    std::string pos1,pos2,pos3;
    std::string mensaje,mensaje_cifrado;
    enig();
    enig(std::string,std::string);
    enig(std::string,std::string,std::string,std::string,std::string);
    void alfabeto_aleatorio();
    
    std::string cifrado();
    void transformar(std::string&,  std::string&,  std::string&, int);
    
    
    
    std::string decifrado();
    std::string alfa_1,alfa_2,alfa_3,alfa1,alfa2,alfa3;
    
    
private:
    std::string alfabeto = "abcdefghijklmnopqrstuvwxyz";
};
#endif /* enig_hpp */
