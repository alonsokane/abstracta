//
//  rsa.cpp
//  abstracta
//
//  Created by alonso paucar ugarte on 10/7/19.
//  Copyright © 2019 alonso paucar ugarte. All rights reserved.
//

#include "rsa.hpp"
rsa::rsa(std::string m){
    me=m;
    n=p*q;
    øn=(p-1)*(q-1);
    e=rand()%øn;
    while (modulo_template(e, øn)!=1){
       e=rand()%øn;
    }
    d=inv(e, øn);
    
}
rsa::rsa(long long a,long long b){
    e=a;
    n=b;
}
std::string rsa::cifrado(){
    for(int i=0;i<me.length();i++){
        long long c=potencia(alfa.find(i), e, n);
        ci+=alfa[c];
    }
    return ci;
}
std::string rsa::decifrado(){
    for(int i=0;i<me.length();i++){
        long long c=potencia(   , d, n);
        ci+=alfa[c];
    }
    return ci;
}
void rsa::criba(bool m[],int tam){
    m[0] = false;
    m[1] = false;
    for(int i = 2; i <= tam; ++i){
        m[i] = true;
    }
    for(int i = 2; i*i <= tam; ++i) {
        if(m[i]) {
            for(int h = 2; i*h <= tam; ++h)
                m[i*h] = false;
        }
    }
}
