#include <iostream>
#include "include/ABB.h"
#include "include/dni_name.h"

void update(int count, int &max,int &min,int &acumulado)
{

    if(min==0)
        min=count;
    else
        if(min>count)
            min=count;

    if(max==0)
        max=count;
    else
        if(max<count)
            max=count;

    acumulado+=count;
}

int main()
{

    int op;
    int dummy;

    cout<<"¿Qué modo desea escoger?\n";
    cout<<"0.Salir\n";
    cout<<"1.Desmostración\n";
    cout<<"2.Estadística\n>";


    cin>>op;

    switch (op) {
    case 1:
    {
        //Modo desmostración

        ABB<dni_name> arbol;

        unsigned long value;


        while(op!=0)
        {
            system("clear");
            arbol.write(cout);


            cout<<"\n\nElija una opción:\n";
            cout<<"0.Salir\n";
            cout<<"1.Insertar Clave\n";
            cout<<"2.Eliminar Clave\n>";

            cin>>op;


            switch (op)
            {

            case 1:
                cout<<"Introduce el elemento a insertar:\n";
                cin>>value;
                arbol.insertar(*new dni_name (value,'R',"a","a"),dummy);
                break;

            case 2:
                cout<<"Introduce el elemento a eliminar:\n";
                cin>>value;
                arbol.eliminar(*new dni_name (value,'R',"a","a"));

            default:
                break;
            }

        }

        break;
    }

    case 2:
    {
        //Modo estadiística

        int N,nPruebas,max1,min1,acumulado1,count,max2,min2,acumulado2;
        max1=min1=acumulado1=max2=min2=acumulado2=count=0;

        ABB<dni_name> arbol;

        vector<dni_name> banco;

        cout<<"Introduce el tamaño del arbol:\n";
        cin>>N;

        cout<<"Introduce el número de pruebas:\n";
        cin>>nPruebas;

        //Crear banco
        for(int i=0; i < 2*N; i++)
        {
            banco.push_back(*new dni_name);
        }

        //Insertar N elementos en arbol
        for(int i = 0; i < N; i++)
        {
            arbol.insertar(banco[i],dummy);
        }

        //Busca los N Primeros elementos del banco
        for(int i = 0; i < N; i++)
        {
            count=0;
            arbol.buscar(banco[i],count);
            update(count,max1,min1,acumulado1);
        }

        //Busca desde N hasta 2*N en el arbol
        for(int i = N; i < 2*N; i++)
        {
            count=0;
            arbol.buscar(banco[i],count);
            update(count,max2,min2,acumulado2);
        }


        system("clear");
        cout<<"Numero de comparaciones\n\n";
        cout<<"\t\tN\tPruebas\tMínimo\tMedio\tMáximo\n";
        cout<<"Búsqueda\t" << N << "\t" << nPruebas << "\t" << min1  << "\t" << acumulado1/N << "\t" << max1 <<"\n";
        cout<<"Inserción\t" << N << "\t" << nPruebas << "\t" << min2  << "\t" << acumulado2/N << "\t" << max2 <<"\n";







    break;
    }


    default:
    cout<<"Saliendo...\n";
        break;

    }




 return 0;
}
