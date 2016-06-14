//
// Created by leandro on 14/06/16.
//

#ifndef LAB6_ISESION_H
#define LAB6_ISESION_H

#include <string>
using namespace std;

class ISesion {
public:
    virtual bool isLogged() = 0;
    virtual bool esTipo(string tipo) = 0;
    virtual ~ISesion() = 0;
};


#endif //LAB6_ISESION_H
