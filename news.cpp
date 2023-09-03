#ifndef _NEWS_
#define _NEWS_ 1
#include <iostream>
#include <string>

using namespace std;

class News {
private: 
    string title;
    string content;

public:
    News(){}
    News(string pTitle, string pContent) {
        title = pTitle;
        content = pContent;
    }

    string getTitle() {
        return title;
    }

    string getContent() {
        return content;
    }

    void byRelevance(CircularLinkedList list) {
        list.display();
    }
    void relevanceByInput(CircularLinkedList list, News pArray[]) {
        list.inputRelevance(pArray);
        list.display();
    }
    void deleteByInput(CircularLinkedList list, News pArray[]) {
        list.deleteInput(pArray);
        list.display();
    }
    void reubicateTitular(CircularLinkedList list, int pPosition, string moveTo ){
        list.reubicate(pPosition, moveTo);
        list.display();
    }
    void getTop5(CircularLinkedList list) {
        list.displayTop5();
    }
};

#endif