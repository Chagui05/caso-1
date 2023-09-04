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
        for(int currNode = 1; currNode <= max; currNode++){
            News* currNews = list->findNode(currNode);
            string texto = currNews->getTitle();
            for(int count = 0 ; count  < pCount ; count++ ){
                if(texto.find(pArray[count]) != string::npos){
                    News* removed = list->removeIndex(currNode);
                    list->addToFront(removed);
                    
                }
            }
        }
    }
    void deleteByInput(CircularLinkedList* list, string pArray[], int pCount) {
        string texto;
        int max = list->countNodes();
        for(int currNode = 1; currNode <= max; currNode++){
            News* currNews = list->findNode(currNode);
            string texto = currNews->getTitle();
            for(int count = 0 ; count  < pCount ; count++ ){
                if(texto.find(pArray[count]) != string::npos){
                    int pos = list->nodePosition(currNews);
                    News* removed = list->removeIndex(pos);
                    currNode= 1;
                    
                }
            }
        }
    }
    //
    void reubicateTitular(CircularLinkedList* list, int pPosition, string moveTo ){
        News* aux = list->findNode(pPosition);
        string direction = moveTo.substr(0,1);
        int newPos = stoi(moveTo.substr(1,2));
        if (direction == "-"){
            int where = pPosition+newPos;
            if (where > list->countNodes()){
                where = list->countNodes();       
            }
            News* removed = list->removeIndex(pPosition);
            list->addToIndex(removed, where);
        }
        else{
            int where = pPosition - newPos;
            if (where < 0){
                where = 1;     
            }
            News* removed = list->removeIndex(pPosition);
            list->addToIndex(removed, where);

        }
    }

};
#endif