//
//  main.cpp
//  abstracta
//
//  Created by alonso paucar ugarte on 9/9/19.
//  Copyright © 2019 alonso paucar ugarte. All rights reserved.
//


#include "vigenere.hpp"
#include "verman.hpp"   
#include "culebra.hpp"
#include "/Users/alonsopaucarugarte/Desktop/abstracta/abstracta/euclides.h"
#include "enig.hpp"
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include "afin.hpp"
#include "protocolo.hpp"
#include <iostream>
#include <fstream>
using namespace euclides;
void escribir(std::string nombre, std::string mensaje){
    std::ofstream archivo;
    archivo.open(nombre,std::ios::out);
    if(archivo.fail()){
        std::cout<< "no se pudo abrir el archivo";
        exit(1);
    }
    archivo<<mensaje;
    archivo.close();
}
std::string leer(std::string nombre){
    std::ifstream archivo;
    std::string mensaje;
    archivo.open(nombre,std::ios::in);
    if(archivo.fail()){
        std::cout<< "no se pudo abrir el archivo";
        exit(1);
    }
    while(!archivo.eof()){
        getline(archivo,mensaje);
    }
    archivo.close();
    return mensaje;
}

int main(int argc, const char * argv[]) {
    /*
    vigenere b("alonso rodrigo paucar ugarte 1234098");
    std::string me=b.cifrado();
    //std::cout<<me<<std::endl;
     
    vigenere e("nm3vnwgr86pzgwcl97611fjoh18etqlf71qh0k0d5sr1fwjhabqw8kc3xsrua1cij8ji4qbvj3fl3vganybnryf6wkvfy63qb","g9svou3fu7lhywvm9vyvng8g42nebrlgy1fhjlwwmoszwf24b8dx43uzyani7ju2f955nasrkkwm0rz3ihbkdzbodkw4yv4cc6hd4s0kfiw");
    std::string decifrado=e.decifrado();
    std::cout<<decifrado<<std::endl;
    */
    /*
    verman me("hola amigui","alonso123pa");
    std::string msj=me.cifrado();
    //verman  m("000010001001001011001100010001100000010000001000001101011110110100000010000011010100010011010110110110000011010010100100001111011111000001000000011001101010000001000011100011001100001100000110001001000010010101110100011101000011000011101110000100100101001000011011011010001100011110000101000010","fhaedesgbqqgrhtespwadlfrxochhlmkitrqvshkebkvwipxf5");
    std::cout<<msj;
    */
    
    //culebra c(8,10,"C es un lenguaje de programación diseñado en 1979 por Bjarne Stroustrup");
    //std::string cifra =c.cifrado();
    //(fila,columnas)
    /*culebra b(11,10,"trus5wwwwwweeat wwwwwwn nabwwwwwwgyt ywwwwwwo al wwwwww nraewwwwwwhoeslwwwwwwa   iwwwwwwmah3awwwwwwbga1swwwwww" );
    std::string deci=b.decifrado();
    std::cout<< deci<<std::endl;
    */
    /*
    std::string mensaje="holahermano";
    std::string clave="xop";
    enig a(mensaje,clave);
    std::string me=a.cifrado();
    
    
    std::cout<<me<<std::endl;
  
    enig b(me,a.r1,a.r2,a.r3,clave);
   
    std::cout<<b.decifrado();
    */
    
    /*
    Afin a1;
    std::string men="alonso";
    std::string ci=a1.cifrar(men);
    Afin b(a1.a,a1.b);
    std::string de=b.descifrar(ci);
    std::cout<<ci<<std::endl<<de<<std::endl;
    */
    protocolo p("alonso","xyv",2,13);
    std::string men=p.clave();
    std::cout<<men<<std::endl;
    
    
    escribir( "/Users/alonsopaucarugarte/Desktop/abstracta/abstracta/men.txt" , men);
    std::string me=leer("/Users/alonsopaucarugarte/Desktop/abstracta/abstracta/men.txt");
    
    protocolo po(me);
    std::cout<<po.descifrado();
    return 0;
}

