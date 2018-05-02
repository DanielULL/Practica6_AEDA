#ifndef NODOBB_H
#define NODOBB_H

#include <iostream>

template <class clave>
class nodoBB
{

private:

    nodoBB* izq;
    nodoBB* dcha;
    clave   clave_;

public:

    nodoBB():
    izq(NULL),dcha(NULL)
    {}

    nodoBB(clave clave__):
    izq(NULL),dcha(NULL),clave(clave_)
    {}

    nodoBB(nodoBB* izq_,nodoBB* dcha_,clave clave__):
    izq(izq_),dcha(dcha_),clave_(clave__)
    {}

    ~nodoBB()
    {
        izq=NULL;
        dcha=NULL;

    }




    nodoBB* &get_izq()
    {
        return izq;
    }

    nodoBB* &get_dcha()
    {
        return dcha;
    }




    clave &get_clave()
    {
        return clave_;
    }



    void set_izq(nodoBB* izq_)
    {
        izq = izq_;
    }

    void set_dcha(nodoBB* dcha_)
    {
        dcha = dcha_;
    }




    void set_clave(nodoBB* clave__)
    {
        clave_ = clave__;
    }






};

#endif // NODOBB_H
