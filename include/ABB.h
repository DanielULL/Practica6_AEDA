#ifndef ABB_H
#define ABB_H

#include "include/nodoBB.h"
#include <queue>
#include <utility>

using namespace std;

template <class clave>
class ABB
{
private:
    nodoBB<clave>* raiz;

public:

    ABB():
    raiz(NULL)
    {}

    ABB(nodoBB<clave>* raiz_):
    raiz(raiz_)
    {}


    nodoBB<clave>* buscar(clave clave_,int &count)
    {
        return busqueda(raiz,clave_,count);
    }

    nodoBB<clave>* busqueda(nodoBB<clave>* nodo, clave clave_,int &count)
    {

        if(nodo==NULL)
            return NULL;

        count++;
        if(nodo->get_clave() == clave_)
            return nodo;


        else
        {
            count++;
            if(nodo->get_clave() < clave_)
                return busqueda(nodo->get_izq(), clave_,count);

            else
                return busqueda(nodo->get_izq(), clave_,count);
        }

        return NULL;
    }




    bool insertar(clave clave_, int &count)
    {
        return insercion(raiz,clave_,count);
    }

    bool insercion(nodoBB<clave>* &nodo, clave clave_, int &count)
    {
        count++;
        if(nodo==NULL)
        {
           nodo = new nodoBB<clave> (NULL,NULL,clave_);
           return true;
        }

        count++;
        if(clave_ < nodo->get_clave())
            return insercion(nodo->get_izq(), clave_,count);

        count++;
        if(clave_ > nodo->get_clave())
            return insercion(nodo->get_dcha(), clave_,count);


        return false;
    }





    bool eliminar(clave clave_)
    {
        return eliminacion(raiz,clave_);
    }

    bool eliminacion(nodoBB<clave>* &nodo, clave clave_)
    {
        if(nodo==NULL)
           return false;


        if(clave_ < nodo->get_clave())
            return eliminacion(nodo->get_izq(),clave_);

        else if(clave_ > nodo->get_clave())
            return eliminacion(nodo->get_dcha(),clave_);

        else
        {
            nodoBB<clave>* eliminado=nodo;

            if(nodo->get_dcha()==NULL)
            {
                nodo=nodo->get_izq();


            }

            else if(nodo->get_izq()==NULL)
            {
                nodo=nodo->get_dcha();
            }

            else
            {
                sustituye(eliminado, nodo->get_izq());
            }



            delete eliminado;
            return true;
        }


        return false;
    }

    void sustituye(nodoBB<clave>* &eliminado, nodoBB<clave>* &sust )
    {
        if (sust->get_dcha() != NULL)
            sustituye(eliminado, sust->get_dcha());
        else
        {
            eliminado->get_clave() = sust->get_clave();
            eliminado = sust ;
            sust = sust->get_izq() ;
        }

    }

 /*  void write1()
    {
        write(raiz,cout);
    }

    ostream& write( nodoBB<clave> *nodo, ostream& os)
    {
     if (nodo == NULL) return os;
     write(nodo->get_izq(),os);
     os<<nodo->get_clave() << "\n";
     write(nodo->get_dcha(),os);
     return os;
     }*/

    ostream& write(ostream& os) const
    {
        queue<pair<nodoBB<clave>*,int>> Q;


         int Nivel_actual = 0;

         Q.push(*new pair<nodoBB<clave>*,int> (raiz,0));
         os<<"Nivel 0: ";

         while (!Q.empty())
         {
             pair<nodoBB<clave>*,int> aux;
             aux = Q.front();
             Q.pop();

             if(aux.second > Nivel_actual)
             {
                 os << "\n";
                 Nivel_actual = aux.second;
                 os<<"Nivel " << aux.second << ": ";
             }



             if(aux.first != NULL)
             {

                 os<<aux.first->get_clave() << " ";

                 Q.push(*new pair<nodoBB<clave>*,int> (aux.first->get_izq(), aux.second+1 ));
                 Q.push(*new pair<nodoBB<clave>*,int> (aux.first->get_dcha(), aux.second+1 ));
             }
             else
             {
                 os<<"[.] ";
             }
          }
         os<<"\n";
         return os;
    }

};

#endif // ABB_H
