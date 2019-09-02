//
// Created by Fabrizio Vásquez on 8/27/19.
//

#include "MyVector.h"


UTEC::MyVector::MyVector(): data(nullptr),nelem(0) {

}

UTEC::MyVector::MyVector(int n) : nelem(n) {
    data = new int[nelem];
    nelem = 0; //Inicializando
}

UTEC::MyVector::~MyVector() {
    //Eliminando objetos de memoria
        delete [] data;

}

int UTEC::MyVector::size() {
    //Retorna el tamaño de un Objeto del tipo MyVector
    return nelem;
}

void UTEC::MyVector::push_back(int item) {
    int *temp = new int [nelem+1];

    for(int i =0 ;i<nelem;i++){
        temp[i]=data[i];
    }
    delete [] data;
    data = temp;

    data[nelem] = item;
    nelem++;
    /*
    if(nelem == reserva){
        nelem++;
        int *array_items = new int[nelem];
        for(int i = 0; i < nelem; i++)
            array_items[i]= data[i];

        delete [] data;
        data = array_items;
    }
    data[nelem] = item;
    nelem ++;
    */
}

void UTEC::MyVector::print_data(){
    for(int i = 0;i<nelem;i++){
        cout<<"\nElementos "<<i<<" : "<<data[i];
    }
}

void UTEC::MyVector::insert(int index, int item) {
    int aux = 0;
    int *array_insert = new int[nelem+1];       //creo el array para poder alamacenar data.
    for(int i = index;i<nelem;i++){

        array_insert[index] = item;
        array_insert[i+1] = data[i];
        /*aux = data[index];
        array_insert[index] = item;
        array_insert[i] = data[i];
        array_insert[index+i] = aux;
        */
    }
    delete [] data;
    data = array_insert;
    nelem++;

}

int UTEC::MyVector::pop_back() {

    data[nelem] = NULL;
    nelem--;
    return data[nelem-1];
    //hacer el try y catch;
}

int UTEC::MyVector::operator[](int index) {
    try {
        if (index < 0 || index > nelem) {
            throw runtime_error("Fuera del límite de la matriz");
        }
    }
    catch(exception &e){
        cout<<e.what()<<endl;
    }
    return data[index];
}

void UTEC::MyVector::erase(int index) {
    try {
        if( index > nelem){
            throw std::runtime_error("Fuera de límite");
        }
    }
    catch (std::exception& e){
        std::cout << e.what();
    }

    //int data_erase = data[index];
    for (int i = index; i < nelem; ++i) {
        data[i] = data[i+1];
    }
    nelem --;
    //return data_erase;
}

UTEC::MyVector &UTEC::MyVector::operator+(UTEC::MyVector &v1) {
    MyVector aux(v1);
    for (int i = 0; i < v1.nelem; ++i) {
        aux.data[i] = aux.data[i] + this->data[i];
    }
    return *this;
}




/*
UTEC::MyVector &UTEC::MyVector::operator+(MyVector &one) {

    MyVector *aux;
    for(int i = 0;i<nelem;i++){
        aux->data[i] = data[i] + one.data[i];
        cout<<"\n"<<aux->data[i];
    }
    return *this;
}
 */

int UTEC::MyVector::getData(int i) const {
    return data[i];
}


