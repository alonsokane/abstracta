//
//  enigma.cpp
//  abstracta
//
//  Created by alonso paucar ugarte on 9/14/19.
//  Copyright © 2019 alonso paucar ugarte. All rights reserved.
//

#include "enigma.hpp"
#include <iostream>


using namespace euclides;

Enigma::Enigma()
{
    
    pos33 = int(alfabeto.find("A"));
    pos22 = int(alfabeto.find("A"));
    pos11 = int(alfabeto.find("A"));
    rotor1 = alfabeto_aleatorio();
    rotor2 = alfabeto_aleatorio();
    rotor3 = alfabeto_aleatorio();
    l1 = int(alfabeto.find("Z"));
    l2 = int(alfabeto.find("Z"));
    l3 = int(alfabeto.find("Z"));
  
}
Enigma::Enigma(std::string rotor1,std::string rotor2,std::string rotor3){
    this->rotor1=rotor1;
    this->rotor2=rotor2;
    this->rotor3=rotor3;
}
std::string Enigma::alfabeto_aleatorio(){
    int i=0;
    std::string alfa;
    srand( static_cast<unsigned int>(time(NULL)));
    int nun[alfabeto.length()];
    bool t=true;
    while (i<alfabeto.length()) {
        t=true;
        int b=rand()%int(alfabeto.length());
        for (int j=0;j<i;j++){
            if(nun[j]==b){
                t=false;
            }
            
        }
        if(t){
            nun[i]=b;
            //std::cout<<nun[i]<<",";
            i++;
            alfa+=alfabeto[b];
        }
        
    }
    //system("pause>nul");
    //std::cout <<i<<std::endl;
    return alfa;
}
std::string Enigma::cifrado(std::string mensaje)
{
    std::string cifrar;
    std::string mensaje_cifrado;
    std::string st;
    std::string st1;
    std::string s;
    int pos1=pos11;
    int pos2=pos22;
    int pos3=pos33;
    int largo=int(alfabeto.length());
    for (int i = 0; i < int(mensaje.length()); i++) {
        
        cifrar = mensaje[i];
        //std::cout<<cifrar<<"    aca"<<std::endl;
        pos1 = modulo(++pos1, largo);
        
        if (pos1 == l1)
        {
            pos2 = modulo(++pos2, largo);
            if (pos2 == l2)
            {
                pos3 = modulo(++pos3, largo);
            }
        }
        transformar(cifrar, alfabeto, rotor1, pos1);//primer rotor
        transformar(cifrar, alfabeto, rotor2, pos2);//segundo rotor
        transformar(cifrar, alfabeto, rotor3, pos3);//tercer rotor
        //transformar(cifrar, alfabeto, reflector, 0);//uso del reflector
        //transformar(cifrar, rotor3, alfabeto, pos3);//tercer rotor de regreso
        //transformar(cifrar, rotor2, alfabeto, pos2);//segundo rotor de regreso
        //transformar(cifrar, rotor1, alfabeto, pos1);//segundo rotor de regreso
        
        mensaje_cifrado += cifrar;
    }
    return mensaje_cifrado;
}
void Enigma::transformar(std::string &mensaje,  std::string &entra,  std::string &salida, int suma){
    int agregar = int(alfabeto.find(mensaje)) + suma;
    //std::cout<<mensaje<<"inicio"<<std::endl;
    agregar = modulo(agregar, int(entra.length()));
    //std::cout <<suma<<"plplplp"<<agregar<<std::endl;
    mensaje = alfabeto[agregar];
    //std::cout <<mensaje<<std::endl;
    agregar = int(entra.find(mensaje));
    //std::cout <<agregar<<"ssssssssss"<<std::endl;
    mensaje = salida[agregar];
    //std::cout <<mensaje<<std::endl;
    agregar = int(alfabeto.find(mensaje)) - suma;
    
    agregar = modulo(agregar, int(entra.length()));
    //std::cout <<agregar<<"dfdfdfdfd"<<std::endl;
    mensaje = alfabeto[agregar];
    //std::cout <<alfabeto[agregar]<<"fin"<<std::endl;
    
    
}

std::string Enigma::r1(){
    return rotor1;
    
}
std::string Enigma::r2(){
    return rotor2;
    
}
std::string Enigma::r3(){
    return rotor3;
    
}

