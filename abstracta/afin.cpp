//
//  afin.cpp
//  abstracta
//
//  Created by alonso paucar ugarte on 9/23/19.
//  Copyright © 2019 alonso paucar ugarte. All rights reserved.
//

#include "afin.hpp"
//Constr para encriptar
Afin::Afin()
{
    //Size alfabeto
    size = int(alfaafin.length());

    //Seed rand() con time.h
    //    srand(unsigned(time(NULL)));

    //Genera a y b al azar
    a = modulo(rand(), size);
    b = modulo(rand(), size);

    //Check si mcd(a,N)=1
    while (mcd(a, size) != 1)
        a = modulo(rand(), size);
}

//Constr para desencriptar
Afin::Afin(int x, int y)
{
    //Size alfabeto
    size = int(alfaafin.length());

    a = x;
    b = y;
    //halla inversa de a
    ai = modulo(inversa(a, size), size);
}

//Inversa llama euclides extendido
int Afin::inversa(int a, int b)
{
    return eu_extendido(a, b)[1];
}

std::string Afin::cifrar(std::string m)
{
    std::string mc;
    int temp;
    for (int i = 0; i < m.length(); i++) {
        //busca letra en el abecedario
        temp = int(alfaafin.find(m[i]));
        //Se aplica funcion a la letra en numero
        temp =modulo(temp * a, size);
        temp =modulo(temp + b, size);

        //Se pasa numero a letra en el abecedario
        //Append a resultado
        mc += alfaafin[temp];
    }
    return mc;
}

std::string Afin::descifrar(std::string mcifra)
{
    std::string men;
    int temp = 0;

    for (int i = 0; i < mcifra.length(); i++) {
        temp = int(alfaafin.find(mcifra[i]));
        temp = modulo(temp - b, size);
        temp = modulo(temp * ai, size);
        men += alfaafin[temp];
    }
    return men;
}
