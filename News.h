#ifndef _NEWS_
#define _NEWS_ 1
#include <iostream>
#include <string>
#include "CircularLinkedList.h"
#include "Node.h"
using namespace std;

class News {
private: 
    string title;
    string content;

public:
    News() : title(nullptr), content(nullptr) {};

    News(string pTitle, string pContent) {
        title = pTitle;
        content = pContent;
    }
    
    bool operator==(News pNews)const{
        return pNews.title == title && pNews.content == content;
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
    void deleteByInput(CircularLinkedList list, News pArray[], int count) {
        list.deleteInput(pArray, count);
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