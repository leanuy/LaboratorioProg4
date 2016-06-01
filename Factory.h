//
// Created by Santiago Serantes on 6/1/16.
//

#ifndef LAB3_FACTORY_H
#define LAB3_FACTORY_H


class Factory {
private:
    static Factory * instance;
public:
    static Factory * getInstance();
    ILog getILog();
    IPropiedades getIPropiedades();
    IConversaciones getIConversaciones();
    IUsuarios getIUsuarios();
};


#endif //LAB3_FACTORY_H
