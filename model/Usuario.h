//
// Created by leandro on 01/06/16.
//

#ifndef LAB6_USUARIO_H
#define LAB6_USUARIO_H

#include <string>

using namespace std;

class Usuario {
private:
    string email;
    string contrasenia;
    bool firstLogin;
public:
    virtual ~Usuario() = 0;

    void setEmail(string mail);
    string getEmail();
    void setContrasenia(string contra);
    string getContrasenia();

    bool getFirstTime();
    void setFirstTime(bool);
    bool AsignarPassword(string pass1,string pass2);
    bool CheckPassword(string pass);

    virtual bool esTipo(string tipo)=0;
};


#endif //LAB6_USUARIO_H
