#ifndef DNI_NAME_H
#define DNI_NAME_H

#define DIGITS 2

#include <iostream>
#include <string>
#include "cmath"
#include "time.h"


class dni_name
{
private:
    unsigned long dni;
    char letra;
    string nombre;
    string apellido;

public:

    dni_name():
    dni(0),nombre("Daniel"),apellido("Suárez")
    {
        letra = (rand() % 27) + 65;

        for(unsigned i = 0; i < DIGITS; i++)
        {
            dni+= (rand() % 10) * (pow(10, i ));
        }
    }

    dni_name(unsigned long d):
    dni(d),nombre("Daniel"),apellido("Suárez")
    {
        letra = (rand() % 27) + 65;
    }

    dni_name(unsigned long d,char letra_,string nombre_, string apellido_):
    dni(d),letra(letra_),nombre(nombre_),apellido(apellido_)
    {

    }


    ostream &write(ostream &out) const
    {
        cout.fill  ('0');
        cout.width ( DIGITS );

        out << dni << letra << " " << nombre <<" " << apellido ;
        return out;
    }

    friend ostream& operator<<(ostream& os, const dni_name& dni_name_)
    {
        cout.fill  ('0');
        cout.width ( DIGITS );

        os << dni_name_.dni << dni_name_.letra;

        return os;
    }

    bool operator==(dni_name& other)
    {
        if(other.dni==dni && other.letra==letra)
            return true;

        else
            return false;
    }

    operator unsigned long()
    {
        return dni;
    }


    bool operator<(dni_name &other)
    {
        if(dni==other.dni)
        {
            if(letra<other.letra)
                return true;
            else
                return false;
        }

        return (dni<other.dni);

    }

    bool operator>(dni_name &other)
    {

        if(dni==other.dni)
        {
            if(letra>other.letra)
                return true;
            else
                return false;

        }

        if(dni>other.dni)
            return true;
        else
            return false;

    }

    void operator=(dni_name& other)
    {
        dni=other.dni;
        letra=other.letra;
        nombre=other.nombre;
        apellido=other.apellido;
    }

};
#endif // DNI_NAME_H
