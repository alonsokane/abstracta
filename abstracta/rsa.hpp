//
//  rsa.hpp
//  abstracta
//
//  Created by alonso paucar ugarte on 10/7/19.
//  Copyright © 2019 alonso paucar ugarte. All rights reserved.
//

#ifndef protocolo_hpp
#define protocolo_hpp
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include "/Users/alonsopaucarugarte/Desktop/abstracta/abstracta/euclides.h"
#include <vector>
using namespace euclides;
class rsa{
public:
    long long n,øn,e;
    std::string ci,di,me;
    rsa(std::string);
    rsa(long long,long long);
    std::string cifrado();
    std::string decifrado();
private:
    const std::string alfa = "abcdefghijklmnopqrstuvwxyz0123456789";
    long p,q,d;
    int tam=0;
    bool m[];
    void criba(bool[],int);
    
    
};
#endif /* protocolo_hpp */
