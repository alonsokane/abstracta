//
//  culebra.hpp
//  abstracta
//
//  Created by alonso paucar ugarte on 9/9/19.
//  Copyright © 2019 alonso paucar ugarte. All rights reserved.
//

#ifndef culebra_hpp
#define culebra_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
class culebra{
    public:
    std::string mensaje;
    std::string me_cifrado;
    culebra(int,int,std::string);
    std::string cifrado();
    std::string decifrado();
    private:
    int ci;
    int cj;
    std::string llenado(std::string,int);
    
};
#endif /* culebra_hpp */
