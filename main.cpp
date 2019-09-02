#include <iostream>
#include <cassert>
#include "MyVector.h"
#include "vector"
#include "exception"

using namespace std;
using namespace UTEC;

int main() {
    //std::vector<UTEC::MyVector*> *vector = new std::vector<UTEC::MyVector*>();

    //Declarando objetos v1,v2,v3 de tipo My vector
    auto *v1 = new MyVector(); //MyVector v1
    auto *v2 = new MyVector(); //MyVector v2
    auto *v3 = new MyVector();  //MyVector v3


    //Verificando que los dos arrays v1 y v2 contiene el mismo tamaño de almacenamiento
    for (int i = 0; i < 100; ++i) {
        v1->push_back(i);
        v2->push_back(i);
        assert(v1->size() == v2->size());
    }


    // Verificando que los dos arrays v1 y v2 se inserta correctamente los datos mediante un bucle


    for (int i =0; i < 50; i++) {
        v1->push_back(i);
        v2->push_back(i);
        //cout<<v1->getData(i)<<"    "<<v2->getData(i)<<"\n";
        assert(v1->getData(i) == v2->getData(i));
    }



    //Verificando que se eliminan los datos de los arrays v1 y v2

    for (int i = 0; i < 50; ++i) {
        v1->pop_back();
        v2->pop_back();
        assert(v1->pop_back() == v2->pop_back());
    }



    //Verificando la funcion INSERT
    int x=0;
    for (int i = 0; i < 50; i++) {
        v1->insert(i,i+1);
        v2->insert(x++,i+2);
        assert(v1->size() == v2->size());
    }



    //Verificando la funcion ERASE

    int j = 0;
    for(int i = 0;i<2;i++){
        v1->push_back(i);
        v2->push_back(j++);
        v1->erase(i);
        v2->erase(i);
        assert(v1->size() == v2->size() );
    }

    *v3 = *v1+*v2;
    cout<<v3->size();
    assert(v3->size() == 100 );

    return 0;
}




//Avance del proyecto
//My Vector
//Matriz Compuesta