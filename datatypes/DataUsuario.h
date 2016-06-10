//
// Created by leandro on 10/06/16.
//

#ifndef LAB6_DATAUSUARIO_H
#define LAB6_DATAUSUARIO_H

#include <string>
using namespace std;

class DataUsuario {
private:
    string email;
    string contrasenia;
public:
    virtual ~DataUsuario();
    string getEmail();
    void setEmail(string mail);
    string getPassword();
    void setPassword(string pass);
};


#endif //LAB6_DATAUSUARIO_H
