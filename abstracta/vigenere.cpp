//
//  vigenere.cpp
//  abstracta
//
//  Created by alonso paucar ugarte on 9/16/19.
//  Copyright © 2019 alonso paucar ugarte. All rights reserved.
//

#include "vigenere.hpp"
using namespace euclides;
vigenere::vigenere(std::string me){
    this ->me=me;
    cl=gen_clave();
    
  

}
vigenere::vigenere(std::string me,std::string cl){
    this->me=me;
    this->cl=cl;
}

std::string vigenere::gen_clave(){
    std::string c;
    
    srand( static_cast<unsigned int>(time(NULL)));
    int tam = int(me.length());
    int i=0;
    while (i<tam) {
        
        int auxi=1;
        auxi=rand()%10;
        if (auxi!=0){
            
          
            c=c+std::to_string(auxi);
            i++;
            
        }
    }
    return c;
    
}
std::string vigenere::imp_clave(){
    return cl;
}

std::string vigenere::cifrado(){
    for(int i=0;i<me.length();i++){
        int suma= static_cast<int>(cl[i]);
        int d=int(alfabeto.find(me[i]))+int(alfabeto.find(suma));
        mensaje_cifrado=mensaje_cifrado+alfabeto[modulo(d,int(alfabeto.length()))];
        }
        return mensaje_cifrado;
    }
std::string vigenere::decifrado(){
    for(int i=0;i<me.length();i++){
        int res= static_cast<int>(cl[i]);
        int d=int(alfabeto.find(me[i]))-int(alfabeto.find(res));
        mensaje_decifrado=mensaje_decifrado+alfabeto[modulo(d,int(alfabeto.length()))];
    }
    return mensaje_decifrado;
}
