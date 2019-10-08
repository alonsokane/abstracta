//
//  euclides.h
//  abstracta
//
//  Created by alonso paucar ugarte on 9/14/19.
//  Copyright © 2019 alonso paucar ugarte. All rights reserved.
//

#ifndef euclides_h
#define euclides_h
//#include <NTL/ZZ.h>
#include <vector>
//using namespace NTL;
//NTL_CLIENT;
namespace euclides {
    
    
    template <class t>
    t inline modulo_template (t a, t b){
        t r = a - b * (a / b);
        return (r < 0) ? r += b : r;
    }
    template <class p>
    p inline inv(p a,p b){
        p q, r,
            x = 1,
            x2 = 1,
            x1 = 0,
            y = 0,
            y2 = 0,
            y1 = 1;
        std::vector<p> result(3);

        if (b == 0) {
            result = { a, x, y };
            return x;
        }

        while (b > 0) {
            q = a / b;
            r = a - q * b;
            x = x2 - q * x1;
            y = y2 - q * y1;
            a = b;
            b = r;
            x2 = x1;
            x1 = x;
            y2 = y1;
            y1 = y;
        }
        result = { a, x2, y2 };
        return x2;
    }
    inline int modulo(int a, int b)
    {
        int r = a - (b * (a / b));
        return (r < 0) ? r += b : r;
    }
   inline long long potencia( long long a, long long k,long long z){
       long long exp=1;
       long long xp=a%z;
            while(k>0){
                if((k%2)!=0){
                xp=(exp*xp)%z;
                    
                }
                xp=(xp*xp)%z;
                k=k/2;
            }
            
        return exp;
    }
    template <class m>
    m inline po (m a, m k,m z){
        m exp=1;
        m xp=a%z;
        while(k>0){
            if((k%2)!=0){
             xp=(exp*xp)%z;
                
            }
            xp=(xp*xp)%z;
            k=k/2;
        }
        
    return exp;

    }
    
    inline int mcd(int a, int b)
    {
        int r, d, c;
        r = modulo(a, b);
        d = b;
        while (r > 0) {
            c = d;
            d = r;
            r = modulo(c, d);
        }
        return d;
    }
    inline std::vector<int> eu_extendido(int a,int b){
        
            int q, r,
                x = 1,
                x2 = 1,
                x1 = 0,
                y = 0,
                y2 = 0,
                y1 = 1;
            std::vector<int> result(3);

            if (b == 0) {
                result = { a, x, y };
                return result;
            }

            while (b > 0) {
                q = a / b;
                r = a - q * b;
                x = x2 - q * x1;
                y = y2 - q * y1;
                a = b;
                b = r;
                x2 = x1;
                x1 = x;
                y2 = y1;
                y1 = y;
            }
            result = { a, x2, y2 };
            return result;
        
    };
}
#endif /* euclides_h */
