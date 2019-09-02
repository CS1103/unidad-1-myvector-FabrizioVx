//
// Created by Fabrizio Vásquez on 8/27/19.
//

#ifndef INC_01_MYVECTOR_EJERCICIO__MYVECTOR_H
#define INC_01_MYVECTOR_EJERCICIO__MYVECTOR_H

#include "iostream"
using namespace std;

namespace UTEC {
    class MyVector {
    public:
        /*
        int *array_items = nullptr;
        int item;
        int size = 0;
        */
        int *data;
        int nelem;

    public:

        MyVector();                         //constructor por defect

        MyVector(int size);
        //ctl+shif +d
        int size();                         //Retorna el tamaño del vector
        void push_back(int item);           // agrega un item a la ultima posicion del vector
        void insert(int index, int item);   // agrega un item en una posicion determinada por el usuario al vector
        int pop_back();                     // elimina el ultimo item del vector
        void erase(int index);               // elimina un item de una posicion determinada por el usuario al vector
        void print_data();                  // imprime los items
        int operator[](int index);          //sobrecarga para leer un item del vector
        //MyVector& operator+(MyVector&);
        int getData(int i) const;           //Devuelve un item del vector
        MyVector &operator+(MyVector &);    //sobrecarga de operador + para que suma dos objetos de tipo MyVector


        ~MyVector(); // destructor
    };

}
#endif //INC_01_MYVECTOR_EJERCICIO__MYVECTOR_H
