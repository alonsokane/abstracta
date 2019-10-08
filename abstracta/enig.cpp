//
//  enig.cpp
//  abstracta
//
//  Created by alonso paucar ugarte on 9/24/19.
//  Copyright © 2019 alonso paucar ugarte. All rights reserved.
//

#include "enig.hpp"
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <time.h>
#include <stdlib.h>
enig::enig(){
    
}
enig::enig(std::string m,std::string c){
    mensaje=m;
    
    alfabeto_aleatorio();
    
    r1=rotor1;
    r2=rotor2;
    r3=rotor3;
    pos1=c[0];
    pos2=c[1];
    pos3=c[2];
    alfa_1=alfabeto;
    alfa_2=alfabeto;
    alfa_3=alfabeto;
    std::string re1,ree1,re2,ree2,re3,ree3;
    re1=alfa_1.substr(0,alfabeto.find(pos1));
    ree1=alfa_1.substr(alfabeto.find(pos1),alfabeto.length());
    alfa_1=ree1+re1;
    re1=rotor1.substr(0,alfabeto.find(pos1));
    ree1=rotor1.substr(alfabeto.find(pos1),alfabeto.length());
    rotor1=ree1+re1;
    re2=alfa_2.substr(0,alfabeto.find(pos2));
    ree2=alfa_2.substr(alfabeto.find(pos2),alfabeto.length());
    alfa_2=ree2+re2;
    re2=rotor2.substr(0,alfabeto.find(pos2));
    ree2=rotor2.substr(alfabeto.find(pos2),alfabeto.length());
    rotor2=ree2+re2;
    re3=alfa_3.substr(0,alfabeto.find(pos3));
    ree3=alfa_3.substr(alfabeto.find(pos3),alfabeto.length());
    alfa_3=ree3+re3;
    re3=rotor3.substr(0,alfabeto.find(pos3));
    ree3=rotor3.substr(alfabeto.find(pos3),alfabeto.length());
    rotor3=ree3+re3;
}
enig::enig(std::string m,std::string r1,std::string r2,std::string r3,std::string pos){
    mensaje=m;
    rotor1=r1;
    rotor2=r2;
    rotor3=r3;
    pos1=pos[0];
    pos2=pos[1];
    pos3=pos[2];
    alfa_1=alfabeto;
    alfa_2=alfabeto;
    alfa_3=alfabeto;
    std::string re1,ree1,re2,ree2,re3,ree3;
    re1=alfa_1.substr(0,alfabeto.find(pos1));
    ree1=alfa_1.substr(alfabeto.find(pos1),alfabeto.length());
    alfa_1=ree1+re1;
    re1=rotor1.substr(0,alfabeto.find(pos1));
    ree1=rotor1.substr(alfabeto.find(pos1),alfabeto.length());
    rotor1=ree1+re1;
    
    re2=alfa_2.substr(0,alfabeto.find(pos2));
    ree2=alfa_2.substr(alfabeto.find(pos2),alfabeto.length());
    alfa_2=ree2+re2;
    re2=rotor2.substr(0,alfabeto.find(pos2));
    ree2=rotor2.substr(alfabeto.find(pos2),alfabeto.length());
    rotor2=ree2+re2;
    
    re3=alfa_3.substr(0,alfabeto.find(pos3));
    ree3=alfa_3.substr(alfabeto.find(pos3),alfabeto.length());
    alfa_3=ree3+re3;
    re3=rotor3.substr(0,alfabeto.find(pos3));
    ree3=rotor3.substr(alfabeto.find(pos3),alfabeto.length());
    rotor3=ree3+re3;
}
void enig::alfabeto_aleatorio(){
    int i=0;
    std::string alfa,alfa1,alfa2;
    srand(static_cast<unsigned int>(time(NULL)));
    int nun[alfabeto.length()],nun1[alfabeto.length()],nun2[alfabeto.length()];
    bool t=true;
    bool t1=true;
    bool t2=true;
    while (i<alfabeto.length()) {
        t=true;
        t1=true;
        t2=true;
        int b=rand()%int(alfabeto.length());
        int c=rand()%int(alfabeto.length());
        int d=rand()%int(alfabeto.length());
        for (int j=0;j<i;j++){
            if(nun[j]==b ){
                t=false;
            }
            
        }
        for (int j=0;j<i;j++){
            if(nun1[j]==c ){
                t1=false;
            }
            
        }
        for (int j=0;j<i;j++){
            if(nun2[j]==d ){
                t2=false;
            }
            
        }
        if(t && t2 && t1){
            nun[i]=b;
            nun1[i]=c;
            nun2[i]=d;
            i++;
           
            //std::cout<<nun[i]<<",";
            
            alfa+=alfabeto[b];
            alfa1+=alfabeto[c];
            alfa2+=alfabeto[d];
            
        
            
        }
    }
   
    rotor1=alfa;
    rotor2=alfa1;
    rotor3=alfa2;
    
}

std::string enig::cifrado(){
    int p1,p2,p3;
    std::string cifrar;
    p1=0;
    p2=0;
    p3=0;
    for(int i=0;i<mensaje.length();i++){
        cifrar=mensaje[i];
        if(i>3){
            p1++;
            p1=modulo(p1, int(alfabeto.length()));
        }
        if(i>7){
            p2++;
            p2=modulo(p1, int(alfabeto.length()));
        }
        if(i>11){
            p3++;
            p3=modulo(p1, int(alfabeto.length()));
        }
        
        transformar(cifrar, alfabeto, rotor1, p1);
        transformar(cifrar, alfa_1, rotor2, p2);
        transformar(cifrar, alfa_2, rotor3, p3);
        transformar(cifrar, alfa_3, alfabeto, p3);
        mensaje_cifrado+=cifrar;
        }
    return mensaje_cifrado;
}
void enig::transformar(std::string& mensaje,  std::string& entra,  std::string& salida, int suma){
    //std::cout<<mensaje<<std::endl;
    int agregar=int(entra.find(mensaje))+suma;
    //std::cout<<agregar<<suma<<std::endl;
    agregar=modulo(agregar+suma, int(alfabeto.length()));
    mensaje=salida[agregar];
    //std::cout<<"ppp"<<mensaje<<std::endl;
    
    
}

std::string enig::decifrado(){
  int p1,p2,p3;
  std::string cifrar;
  p1=0;
  p2=0;
  p3=0;
  for(int i=0;i<mensaje.length();i++){
      cifrar=mensaje[i];
      if(i>3){
          p1--;
          p1=modulo(p1, int(alfabeto.length()));
      }
      if(i>7){
          p2--;
          p2=modulo(p1,int( alfabeto.length()));
      }
      if(i>11){
          p3--;
          p3=modulo(p1,int( alfabeto.length()));
      }
      transformar(cifrar, alfabeto, alfa_3, p3);
      
      transformar(cifrar, rotor3, alfa_2, p3);
      
      transformar(cifrar, rotor2, alfa_1, p2);
      transformar(cifrar, rotor1, alfabeto, p1);
      
      mensaje_cifrado+=cifrar;
             
      //std::cout<<mensaje_cifrado<<mensaje.length()<<std::endl;
  }
    return mensaje_cifrado;
}
