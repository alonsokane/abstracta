//
//  protocolo.cpp
//  abstracta
//
//  Created by alonso paucar ugarte on 10/6/19.
//  Copyright © 2019 alonso paucar ugarte. All rights reserved.
//

#include "protocolo.hpp"
                     //mensaje     pos enig      filas columnas culebra
protocolo::protocolo(std::string m,std::string p,int f,int c){
    me=m;
    enig en;
    en.alfabeto_aleatorio();
    
    filas=f;
    columnas=c;
    alfa1=en.rotor1;
    rotor(alfa1, filas,columnas);
     //std::cout<<me<<"  "<<alfa1<<"  "<<alfa2<<"  "<<alfa3<<std::endl;
    
    
    pos=p;
    
}
protocolo::protocolo(std::string n){
    /*
    alfa1=n.substr(0,alfabeto.length());
    pos=n.substr(alfabeto.length()+1,29);
    std::string f,c;
    std::cout<<alfa1<<"  "<<pos<<std::endl;*/
    std::string m[8];
    int j=0;
    for(int i=0;i<n.length();i++){
        if(n[i]==','){
            j++;
        }
        else{
            m[j]=m[j]+n[i];
        }
    }
    alfa1=m[0];
    filas=std::stoi(m[2]);
    columnas=std::stoi(m[3]);
    rotor(alfa1, filas, columnas);
    
    pos=m[1];
    
    clave_vige=m[4];
    a=std::stoi(m[5]);
    b=std::stoi(m[6]);
    me=m[7];
    //std::cout<<me<<"  "<<alfa1<<"  "<<alfa2<<"  "<<alfa3<<"  pppp"<<std::endl;
}
void protocolo::rotor(std::string alfa1,int filas,int columnas){
    std::string re1,ree1;
    re1=alfa1.substr(0,25);
    ree1=alfa1.substr(25,alfabeto.length());
    std::string aux_alfa1=ree1+re1;
      
    //(fila,columnas)
    culebra cu(filas,columnas,aux_alfa1);
    alfa2=cu.cifrado();
     
    re1=alfa1.substr(0,2);
    ree1=alfa1.substr(2,alfabeto.length());
    aux_alfa1=ree1+re1;
    
    culebra cu1(filas,columnas,aux_alfa1);
    alfa3=cu1.cifrado();
}
std::string protocolo::clave(){
    std::string p;
    
    vigenere vi(me);
    clave_vige=vi.imp_clave();
    c_m=vi.cifrado();
    enig en(c_m,alfa1,alfa2,alfa3,pos);
    c_m=en.cifrado();
    Afin af;
    a=af.a;
    b=af.b;
    c_m=af.cifrar(c_m);
    return alfa1+","+pos+","+std::to_string(filas)+","+std::to_string(columnas)+","+clave_vige+","+std::to_string(a)+","+std::to_string(b)+","+c_m;
}
std::string protocolo::descifrado(){
    
    Afin af(a,b);
    c_m=af.descifrar(me);
    
    enig en(c_m,alfa1,alfa2,alfa3,pos);
    c_m=en.decifrado();
    vigenere vi(c_m,clave_vige);
    c_m=vi.decifrado();
    
    
    
    return c_m;
}
