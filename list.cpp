#ifndef _LIST_
#define _LIST_ 1
#include <iostream>
#include <string>
#include "node.cpp"
#include "news.cpp"
/*
por ahora estoy usando Integers para almacernar los datos del nodo en la mayoria de casos
luego se usara por completo la clase News
*/

using namespace std;

class CircularLinkedList {
private:
    Node* cursor;
    int size = 0;
public:
    CircularLinkedList() : cursor(nullptr) {};
    //
    
    //
    bool empty() {
        return cursor == nullptr;
    }
    //
    const int back() const{       
        return cursor->elem; 
    }
    //
    const int front() const{       
        return cursor->next->elem; 
    }
    //
    void add(int pElem){
        Node* aux = new Node(pElem);
        if(cursor == nullptr){
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
    void addToFront_aux(Node* pNode){ 
        pNode->next = cursor->next;
        cursor->next = pNode;
        size++;   
    }
    //
    void addToFront(Node* pNode){
        Node* first = cursor;
        for(int i = 0; pNode != cursor->next; i++){
            advance();
        }
        remove();
        cursor = first;
        addToFront_aux(pNode);
    }
    void advance(){
        cursor = cursor->next;
    }
    //
    void remove(){
        Node* old = cursor->next;
        if(old == nullptr){
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
    void deleteNode(Node* pNode){
        Node* toDelete = cursor->next;
        Node* first = cursor;
        int counter = 0;
        if(cursor == nullptr){
            cout << "**Empty list**" << endl;
        }
        else if (size == 0){
        cursor = nullptr;
        }
        else{
            while(toDelete != pNode && counter<=size) {
                advance();
                toDelete = cursor->next;
                counter++;
            }
            if (counter<=size){remove(); size--;}   
        }
        cursor = first;
        delete toDelete, first;  
    }
    //
    int countNodes(){
        Node* aux = cursor;
        int count = 0;
        if(aux != nullptr){
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
        if(aux == nullptr){
            cout << "**Empty list**" << endl;
            return;
        }
        else{
            cout << aux->elem << endl;
            aux = aux->next;
            while(aux != cursor){
                cout << aux->elem << endl;
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
    int searchNodeValue(int pElem){
        Node* aux = cursor;
        if(aux == nullptr){
                cout << "**Empty list**" << endl;
                }
        else{ 
            for(int i=1 ; i <= size ; i++){
                if( aux->elem == pElem){
                    cout << aux->elem << endl;
                    return aux->elem;
                }
                aux = aux->next;
            }   
        cout << "Element not found" << endl;
    }
    }
    //
    int nodePosition(int pElem){
        Node* aux = cursor;
        if(aux != nullptr){
            for(int count = 1 ; count <= size ; count++){
                if( aux->elem == pElem){
                    cout <<"*" << count << "*" << endl;
                    return count;
                }
                aux = aux->next;
            }
        }
        cout << "Element not found or empty list" << endl;
    }
    //
    Node* nodeInPosition(int pPosition){
        Node* aux = cursor;
        if(aux != nullptr){
            for(int count = 0; pPosition > count  ; count++){
                if( pPosition == count){
                    return aux;
                }
                aux = aux->next;
            }
        }
        cout << "Element not found or empty list" << endl;
    }
    //
    void showPositions(){
        Node* aux = cursor;
        if(aux != nullptr){
            for(int count = 1 ; count <= size ; count++){
                cout << "Element: "  << aux->elem << "    position: " << count << endl;
                aux = aux->next;
            }
        }
        else{cout << "**Empty list**" << endl;}
    }
    //
    News* searchWord(string pWord){ //retorna el News
        Node* aux = cursor;
        if( cursor != nullptr){
            for(int count = 1 ; count <= size ; count++){
                string search = aux->getData()->getTitle();
                size_t pos = search.find(pWord);
                if(pos != string::npos){                                    
                    cout << search << " " << pos << endl;                
                    return aux->getData();
                }
                aux = aux->next;
            }
        }   
        else {cout << "Element not found or empty list" << endl;}    
    }
    //
    bool searchWordInNode(string pWord, Node* pNode){                          // hacer una funcion que si este da true lo annada al frente y borre de donde estaba
        Node* aux = cursor;
        int count = 0; 
        if( cursor != nullptr){
            for(count ; aux != pNode && count <=size ; count++){
                aux = aux->next;
            }
            if(count <= size){
                string search = aux->getData()->getTitle();
                size_t pos = search.find(pWord);
                if(pos != string::npos){                                    
                    cout << search << " " << pos << endl;                
                    return 1;
                }
            }
                
        }   
        cout << "Element not found or empty list" << endl; 
        return 0;   
    }
    //
    void inputRelevance(const string pArray[]) {///// ordena por relevancia
        Node* aux = cursor;
        int arraySize = sizeof(pArray) / sizeof(pArray[0]);
        if(cursor != nullptr){
            for (int i = 0; i <= size; i++) {
                for (int j = 0; j < arraySize; j++){
                    if(searchWordInNode(pArray[j], aux)){
                        addToFront(aux);
                    }
                }
                aux = aux->next; 
            } 
        }
        
    }
    //
    void deleteInput(const string pArray[]) {///// borra segun los elementos en la lista
        Node* aux = cursor;
        int arraySize = sizeof(pArray) / sizeof(pArray[0]);
        if(cursor != nullptr){
            for (int i = 0; i <= size; i++) {
                for (int j = 0; j < arraySize; j++){
                    if(searchWordInNode(pArray[j], aux)){
                        deleteNode(aux);
                    }
                }
                aux = aux->next; 
            } 
        } 
    }
    //
    void reubicate(int pPosition, string moveTo ){
        int num;
        Node* aux = nodeInPosition(pPosition);
        string direction = moveTo.substr(0,1);
        try{
            int num = stoi(moveTo.substr(1,2));
        }
        catch(invalid_argument) {
            cout << "bad input" << endl;
        };
        if (direction == "+"){
            int where = pPosition-num;
            if (where < 0){
                where = 1;        
            }
            placeInPosition(aux, where);
        }
        else{
            int where = pPosition+num;
            if (where > size){
                where = size;       
            }
            placeInPosition(aux, where);
        }


    }
    //
    void placeInPosition(Node* aux, int pPosition){
        Node* first = cursor;
        if(size == 0 == pPosition){
            cout << "empty list" << endl;
        }
        else if (cursor == nullptr){
            cursor = aux;
        }
        else {
            for(int i = 1 ; i < pPosition ; i++ ){
                advance();
            }
            addToFront(aux);
        }
        cursor = first;
    }
};

int main() {
    CircularLinkedList lista;
    lista.showPositions();
    lista.countNodes();
    lista.add(2);
    lista.add(3);
    lista.add(5);
    lista.add(6);
    lista.nodePosition(6);
    lista.showPositions();
    cout << lista.back() << endl;
    cout << lista.front() << endl;
};
#endif