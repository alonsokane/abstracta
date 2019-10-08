//
//  enigma.hpp
//  abstracta
//
//  Created by alonso paucar ugarte on 9/14/19.
//  Copyright © 2019 alonso paucar ugarte. All rights reserved.
//

#ifndef enigma_hpp
#define enigma_hpp
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "/Users/alonsopaucarugarte/Desktop/abstracta/abstracta/euclides.h"
class Enigma {
private:
    
    int l3, l2, l1, pos33, pos22, pos11;
    std::string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string reflector = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
    
    
public:
    std::string  rotor3, rotor2, rotor1,st,st1,steckers;
    
    
    
    //std::string limites[5]={"R","F","W","K","A"};
    void getMensaje(std::string);
    void transformar(std::string&,  std::string&,  std::string&, int);
    std::string cifrado(std::string);
    Enigma();
    Enigma(std::string,std::string,std::string);
    std::string alfabeto_aleatorio();
    std::string r1();
    std::string r2();
    std::string r3();
    
};
#endif /* enigma_hpp */
