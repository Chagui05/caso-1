#ifndef _NEWSMANAGER_
#define _NEWSMANAGER_ 1
#include <iostream>
#include <string>
#include "CircularLinkedList.cpp"
using namespace std;

class NewsManager{
    public:
    void getTop5(CircularLinkedList* list) {
        for(int currNode = 1; currNode <= 5 && currNode <= list->countNodes(); currNode++){
            News* currNews = list->findNode(currNode);
            cout << currNode << "." << currNews->getTitle() << endl;
        }    
    }
    void byRelevance(CircularLinkedList* list) {
        list->display();
    }
    void relevanceByInput(CircularLinkedList* list, string pArray[], int pCount) {
        string texto;
        int max = list->countNodes();
        cout << "nodos " << max<< endl << endl;
        for(int currNode = 1; currNode <= max; currNode++){
            News* currNews = list->findNode(currNode);
            string texto = currNews->getTitle();
            for(int count = 0 ; count  < pCount ; count++ ){
                cout << texto << endl;
                cout << pArray[count] << endl;
                if(texto.find(pArray[count]) != string::npos){
                    News* removed = list->removeIndex(currNode);
                    list->addToFront(removed);
                    cout << "ade" <<endl;
                }
                cout << endl;
            }
        }
        list->display();
    }
    void deleteByInput(CircularLinkedList* list, string pArray[], int pCount) {
        string texto;
        for(int currNode = 1; currNode <= list->countNodes(); currNode++){
            News* currNews = list->findNode(currNode);
            string texto = currNews->getTitle();
            for(int count = 1 ; count  <= pCount ; count++ ){
                string buscar = pArray[count];
                if(texto.find(buscar)!= string::npos){
                    News* removed = list->removeIndex(currNode);
                }
            }
        }
        list->display();
    }
    //
    void reubicateTitular(CircularLinkedList* list, int pPosition, string moveTo ){
        int num;
        News* aux = list->findNode(pPosition);
        string direction = moveTo.substr(0,1);
        try{
            int num = stoi(moveTo.substr(1,2));
        }
        catch(invalid_argument) {
            cout << "bad input" << endl;
        };
        if (direction == "-"){
            int where = pPosition-num;
            if (where <= 0){
                where = 1;        
            }
            News* removed = list->removeIndex(pPosition);
            list->addToIndex(removed, where);
        }
        else{
            int where = pPosition + num;
            if (where > list->countNodes()){
                where = list->countNodes();       
            }
            News* removed = list->removeIndex(pPosition);
            list->addToIndex(removed, where);

        }
    }

};
#endif