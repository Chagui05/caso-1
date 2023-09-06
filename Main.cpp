#ifndef _MAIN_
#define _MAIN_ 1
#include <iostream>
#include <string>
#include "NewsManager.cpp"
using namespace std;

int main(){
    CircularLinkedList lista2;
    CircularLinkedList* lista2P = &lista2;
    string pArray[3] = {"Former","tres","power"};
    string pArray2[3] = {"Doctor","Army","cuatro"};
    NewsManager manager;

    Newsapi newsapi;
    vector<News *> allrecords = newsapi.getRecords();

    for(int i = 0 ; i < 10 ; i++){
        lista2.add(allrecords.at(i));
    }
    lista2P->showPositions();
    
    /*News* noticia1 = new News("Noticia uno", "contendio de noticia uno");
    News* noticia2 = new News("Noticia dos", "contendio de noticia dos");
    News* noticia3 = new News("Noticia tres", "contendio de noticia tres");
    News* noticia4 = new News("Noticia cuatro", "contendio de noticia cuatro");
    News* noticia5 = new News("Noticia cinco", "contendio de noticia cinco");
    News* noticia6 = new News("Noticia seis", "contendio de noticia seis");
    News* noticia7 = new News("Noticia siete", "contendio de noticia siete");
    cout<<"Añadiendo noticias con tres distintos metodos" << endl<< endl;
    lista2.add(noticia1);
    lista2.add(noticia2);
    lista2.add(noticia3);
    lista2.addToFront(noticia5);
    lista2.addToBack(noticia4);;*/
    cout<< endl<< endl<< endl;
    cout<<"borrando noticias por index " << endl<< endl;
    News* a = lista2.removeIndex(0);
    cout<<"Noticia borrada" << a->getTitle() << endl;
    News* b = lista2.removeIndex(8);
    cout<< "Noticia borrada" << b->getTitle() << endl;
    lista2P->showPositions();cout<< endl<< endl;

    /*cout<<"añadiendo de vuelta noticia cuatro y cinco " << endl<< endl;
    lista2.add(noticia5);
    lista2.add(noticia4);
    lista2P->showPositions();
    cout<< endl<< endl;*/

    cout<<"relevance por este array: {'Former','tres','power'}" ;
    manager.relevanceByInput(lista2P, pArray, 3);cout<< endl<< endl;
    lista2P->showPositions();
    cout <<endl<<endl;

    cout<<"delete por este array: {'cuatro','doctor','army' }" << endl;
    manager.deleteByInput(lista2P, pArray2, 3);cout<< endl;
    lista2P->showPositions();cout<<endl<< endl;
    /*cout<<"añadiendo de vuelta noticia cuatro, tres y dos " << endl;
    lista2.add(noticia2);
    lista2.add(noticia3);
    lista2.addToBack(noticia4);
    lista2P->showPositions();*/
    cout <<endl<<endl;
    cout<<"reubicar posicion 2, -1" << endl << endl;
    manager.reubicateTitular(lista2P, 2, "-1");
    lista2P->showPositions();cout<<endl<<endl;
    /*cout<<"añadiendo 2 nuevas" << endl;
    lista2.add(noticia6);
    lista2.add(noticia7);
    lista2P->showPositions();*/
    cout <<endl<<endl;
    cout<<"mostrando top 5" << endl << endl;
    manager.getTop5(lista2P);
};
#endif