#ifndef _MAIN_
#define _MAIN_ 1
#include <iostream>
#include <string>
#include "NewsManager.cpp"
using namespace std;

int main(){
    
    CircularLinkedList lista2;
    CircularLinkedList* lista2P = &lista2;
    string pArray[3] = {"uno","fff","abc"};
    NewsManager manager;

    News* noticia1 = new News("Noticia uno", "contendio de noticia uno");
    News* noticia2 = new News("Noticia dos", "contendio de noticia dos");
    News* noticia3 = new News("Noticia tres", "contendio de noticia tres");
    News* noticia4 = new News("Noticia uno cuatro", "contendio de noticia cuatro");
    News* noticia5 = new News("Noticia cinco", "contendio de noticia cinco");
    lista2.add(noticia1);
    lista2.add(noticia2);
    lista2.add(noticia3);

    lista2.addToFront(noticia5);
    lista2.addToBack(noticia4);
    cout<< endl;
    lista2P->showPositions();
    cout<< endl;
    lista2.removeIndex(0);
    lista2.removeIndex(8);
    manager.relevanceByInput(lista2P, pArray, 3);cout<< endl<< endl;
    lista2P->showPositions();
    

    
   
};
#endif