#ifndef _CIRCULARLINKEDLIST_
#define _CIRCULARLINKEDLIST_ 1
#include <iostream>
#include <string>
#include "Node.cpp"
using namespace std;

class CircularLinkedList {
private:
    Node* cursor;
    int size = 0;
public:
    Node* getCursor(){
        return cursor;
    }
    string getCursorTitle(){
        return cursor->elem->getTitle();
    }
    CircularLinkedList(){
        cursor = nullptr;
        size = 0;
    };
    //
    ~CircularLinkedList(){ while (!empty()) remove(); }
    //
    bool empty() {
        return size == 0;
    }
    //
    News* back() const{       
        return cursor->elem; 
    }
    //
    News* front() const{       
        return cursor->next->elem; 
    }
    //
    void add(News* pElem){
        Node* aux = new Node(pElem);
        if(size == 0){
            aux->next= aux;
            cursor = aux;
            size++;
        }
        else{
            aux->next = cursor->next;
            cursor->next = aux;
            size++;
        }

    }
    //
    void addToFront(News* pElem){
        if(size == 0){
            add(pElem);
        }
        else{
            News* aux = cursor->elem;
            cursor->elem = pElem;
            add(aux);
        }
    }
    //
    void addToBack(News* pElem){
        addToFront(pElem);
        cursor = cursor->next;
        }
    
    //
    void addToIndex(News* pElem, int index){
        if(index == 1){
            addToFront(pElem);
        }
        else if(size == index){
            addToBack(pElem);
        }
        else{
        Node* aux = cursor;
        for(int i = 2 ; i != index; i++){
            aux = aux->next;
        }
        Node* indexed = new Node(pElem);
        indexed->next = aux->next;
        aux->next = indexed;
        size++;
        }
          
    }
    //
    void advance(){
        cursor = cursor->next;
    }
    //
    void remove(){
        Node* old = cursor->next;
        if(size == 0){
            cout << "**Empty list**" << endl;
            return;}
        if (old == cursor){
        cursor = nullptr;
        }
        else{ 
        cursor->next = old->next;
        }
        size--;
        delete old;   
    }
    //
    News* removeIndex(int index){
        News* old;
        if(size == 0){
            cout << "**Empty list**" << endl;return nullptr;}
        else if(size == 1){old = cursor->elem; cursor = nullptr;}
        else if (index <= 1){
            old = cursor->elem;
            Node* nextNode = cursor->next;
            cursor->elem = nextNode->elem;
            cursor->next = nextNode->next;
            delete nextNode;
            size--;
        }
        else if (index >= size){
            Node* aux = cursor;
            for(; aux->next->next != cursor;){
                aux = aux->next;
            }
            old = aux->next->elem;
            Node* nextNode = aux->next;
            aux->next = cursor;
            size--;
            delete nextNode;   
        }
        else{
            Node* aux = cursor;
            for(int i = 1 ; i != index; i++){
                aux = aux->next;
            }
            old = aux->next->elem;
            Node* nextNode = aux->next;
            aux->elem = nextNode->elem;
            aux->next = nextNode->next;
            size--;
            delete nextNode ;   
        }
        return old;
    }
    //
    int countNodes(){
        Node* aux = cursor;
        int count = 0;
        if(size != 0){
            count++;
            aux = aux->next;
        }
        while(aux!=cursor){
            count++;
            aux = aux->next;
        }
        return count;
    }
    //
    void display() {
        Node* aux = cursor;
        if(size == 0){
            cout << "**Empty list**" << endl;
            return;
        }
        else{
            cout << aux->elem->getTitle() << endl;
            aux = aux->next;
            while(aux != cursor){
                cout << aux->elem->getTitle() << endl;
                aux = aux->next;
            }  
        }
    }
    //
    Node* searchNode(Node* pNode){
        Node* aux = cursor;
        if(size == 0){
                cout << "**Empty list**" << endl;
                }
        else{ 
            for(int i=1 ; i <= size ; i++){
                if( aux == pNode){
                    cout << aux->elem << endl;
                    return aux;
                }
                aux = aux->next;
            }   
        cout << "Node not found" << endl;
    }
    }
    //
    News* searchNodeValue(News* pElem){
        Node* aux = cursor;
        if(size == 0){
                cout << "**Empty list**" << endl;
                }
        else{ 
            for(int i=1 ; i <= size ; i++){
                if(aux->elem == pElem){
                    cout << aux->elem<< endl;
                    return aux->elem;
                }
                aux = aux->next;
            }   
        cout << "Element not found" << endl;
    }
    }
    //
    int nodePosition(News* pElem){
        Node* aux = cursor;
        if(size != 0){
            for(int count = 1 ; count <= size ; count++){
                if(aux->elem == pElem){
                    cout <<"*" << count << "*" << endl;
                    return count;
                }
                aux = aux->next;
            }
        }
        cout << "Element not found or empty list" << endl;
    }
    //

    News* findNode(int pPosition){
        Node* aux = cursor;
        if(size != 0){
            for(int count = 1; pPosition >= count  ; count++){
                if( pPosition == count){
                    return aux->elem;
                }
                aux = aux->next;
            }
        }
        return nullptr;
        cout << "Element not found or empty list" << endl;
    }
    //
    void showPositions(){
        Node* aux = cursor;
        if(size != 0){
            for(int count = 1 ; count <= size ; count++){
                cout << "Element: "  << aux->elem->getTitle() << "    position: " << count << endl;
                aux = aux->next;
            }
        }
        else{cout << "**Empty list**" << endl;}
    }
};


#endif