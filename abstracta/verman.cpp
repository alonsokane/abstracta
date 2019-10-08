//
//  verman.cpp
//  abstracta
//
//  Created by alonso paucar ugarte on 9/9/19.
//  Copyright © 2019 alonso paucar ugarte. All rights reserved.
//

#include "verman.hpp"
#include <string>
#include <math.h>
using namespace euclides;
verman::verman(std::string p,std::string c){
    mensaje=p;
    clave=c;
    tam=int(clave.length());
}
std::string verman::cifrado(){
    int a;
    int b;
    std::string cla;
    for (int i=0;i<tam;i++){
        a=int(alfabeto.find(mensaje[i]));
        b=int(alfabeto.find(clave[i]));
        std::string c1=binario(a);
        std::string c2=binario(b);
        mensaje_cifrado=mensaje_cifrado+fun_xor(c1, c2);
        }
    return mensaje_cifrado;
}
std::string verman::decifrado(){
    int a;
    std::string cla;
    int sum=0;
    for (int i=0;i<tam;i++){
        a=int(alfabeto.find(clave[i]));
        std::string c1=binario(a);
        std::string b=mensaje.substr(sum,6);
        mensaje_cifrado=mensaje_cifrado+alfabeto[numeros(fun_xor(c1, b))];
        sum+=6;
    }

    return mensaje_cifrado;
}

int verman::numeros(std::string m){
    int nun=0;
    int pon=int(m.length())-1;
    for (int i=0;i<int(m.length());i++){
        if(m[i]==uno[0]){
            nun=nun+potencia(2, pon);
        }
        pon--;
    }
    return nun;
}
std::string verman::binario(int pos){
    std::string bi_nun;
    std::string aux;
    if(pos==0){
        aux="0";
    }
    else{
        while (pos>0) {
            if(modulo(pos, 2)==0){
                bi_nun=bi_nun+"0";
            }
            else{
                bi_nun=bi_nun+"1";
            }
            pos=pos/2;
        }
        int con=int(bi_nun.length());
        for (int i=con-1; i>=0; i--) {
            aux=aux+bi_nun[i];
           }
    }
   
    if(aux.length()<6){
        int suma=6-(int(aux.length()));
        for(int i=0;i<suma;i++){
            aux="0"+aux;
            }
    }
    return aux;
}


int verman::num_cifrado(std::string m){
    
    int t=int(m.length());
    int resul=0;
    int cua=0;
    
    for (int i=t-1;i>=0;i--){
        if(m[i]==uno[1]){
            
            int po=(potencia(2,cua));
            resul=resul+po;
            }
        cua++;
        }
    return resul;
}
int verman::potencia( int a, int b){
    int re=1;
    for (re=1;b>0;b--){
       
        re*=a;
    }
    return re;
}


std::string verman::fun_xor(std::string c1,std::string c2){
    
    std::string cla;
    for(int j=0;j<int(c1.length());j++){
        std::string ver;
        if(c1[j]==cero[0]&&c2[j]==cero[1]){
            ver="0";
        }
        if(c1[j]==uno[0]&&c2[j]==uno[1]){
            ver="0";
        }
        if((c1[j]==cerouno[0]&&c2[j]==cerouno[1])||(c1[j]==cerouno[1]&&c2[j]==cerouno[0])){
            ver="1";
        }
        cla=cla+ver;
    }
    //std::cout<<"cla   "<<cla<<std::endl;
    return cla;
}
