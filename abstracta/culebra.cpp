//
//  culebra.cpp
//  abstracta
//
//  Created by alonso paucar ugarte on 9/9/19.
//  Copyright © 2019 alonso paucar ugarte. All rights reserved.
//escitalaaaaa

#include "culebra.hpp"

//(fila,columnas)
culebra::culebra(int i,int j, std:: string s){
    ci=i;
    cj=j;
    mensaje=s;
}
std::string culebra::cifrado(){
    std::string men_cifrado;
    std::vector<std::string> me;
    int sum=0;
   
    if((cj*ci)>mensaje.length()){
        mensaje=llenado(mensaje, cj*ci);
    }
    for (int i=0;i<ci;i++){
        me.push_back(mensaje.substr(sum,cj));
        sum+=cj;
            }
    for (int j=0;j<cj;j++){
        for(int i=0;i<ci;i++){
            men_cifrado=men_cifrado+(me[i][j]);
        }
    }
    return men_cifrado;
    
}
std::string culebra::decifrado(){
    int sum=0;
    std::string men_decifrado;
    for(int k=0;k<ci;k++){
        int sum1=sum;
        for(int p=0;p<cj;p++){
            
            men_decifrado=men_decifrado+ mensaje[sum1];
            sum1+=ci;
            
        }
        sum++;
        
    }
    return men_decifrado;
}
std::string culebra::llenado(std::string a, int b){
    int s=b-int(a.length());
    std::string w="W";
    for (int i=0;i<s;i++){
        a=a+w;
    }
    return a;
}
