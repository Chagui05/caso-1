#ifndef _LIST_
#define _LIST_ 1
#include <iostream>
#include <string>
#include "node.cpp"
#include "news.cpp"
using namespace std;

class CircularLinkedList {
private:
    Node* cursor;
    int size = 0;
public:
    Node* getCursor(){
        return cursor;
    }
    CircularLinkedList() : cursor(nullptr) {};
    //
    ~CircularLinkedList(){ while (!empty()) remove(); }
    //
    bool empty() {
        return cursor == nullptr;
    }
    //
    News back() const{       
        return cursor->elem; 
    }
    //
    News front() const{       
        return cursor->next->elem; 
    }
    //
    void add(News pElem){
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
    void addToFront(News pElem){
        if(cursor == nullptr){
            add(pElem);
        }
        else{
            News aux = cursor->elem;
            cursor->elem = pElem;
            add(aux);
            size++;
        }
    }
    //
    void addToBack(News pElem){
        addToFront(pElem);
        cursor = cursor->next;
        }
    
    //
    void addToIndex(News pElem, int index){
        if(index == 1){
            addToFront(pElem);
        }
        else if(size = index){
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
        if(cursor == nullptr){
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
    News removeIndex(int index){
        News old;
        if(cursor == nullptr){
            cout << "**Empty list**" << endl;
            return;}
        else if (index == 1){
            old = cursor->elem;
            cursor = cursor->next;
        }
        else{
            Node* aux = cursor;
            for(int i = 2 ; i != index; i++){
                aux = aux->next;
            }
            Node* toDelete = aux->next;
            News old = toDelete->elem; 
            aux->next = toDelete->next;
            size--;
            delete toDelete;   
        }
        return old;
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
            cout << aux->elem.getTitle() << endl;
            aux = aux->next;
            while(aux != cursor){
                cout << aux->elem.getTitle() << endl;
                aux = aux->next;
            }  
        }
    }
    //
    void displayTop5() {
        Node* aux = cursor;
        if(aux == nullptr){
            cout << "**Empty list**" << endl;
            return;
        }
        else{
            for(int i = 0 ; i < 5 ; i++){
                cout << aux->elem.getTitle() << endl;
                aux = aux->next;
                if(aux == cursor){break;}
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
                    cout << aux->elem.getTitle() << endl;
                    return aux;
                }
                aux = aux->next;
            }   
        cout << "Node not found" << endl;
    }
    }
    //
    News searchNodeValue(News pElem){
        Node* aux = cursor;
        if(aux == nullptr){
                cout << "**Empty list**" << endl;
                }
        else{ 
            for(int i=1 ; i <= size ; i++){
                if( aux->elem == pElem){
                    cout << aux->elem.getTitle() << endl;
                    return aux->elem;
                }
                aux = aux->next;
            }   
        cout << "Element not found" << endl;
    }
    }
    //
    int nodePosition(News pElem){
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

    News find(int pPosition){
        Node* aux = cursor;
        if(aux != nullptr){
            for(int count = 1; pPosition > count  ; count++){
                if( pPosition == count){
                    return aux->elem;
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
                cout << "Element: "  << aux->elem.getTitle() << "    position: " << count << endl;
                aux = aux->next;
            }
        }
        else{cout << "**Empty list**" << endl;}
    }
    //
    bool searchWordInNode(string pWord, Node* pNode){                          
        Node* aux = cursor;
        int count = 0; 
        if( cursor != nullptr){
            for(count ; aux != pNode && count <=size ; count++){
                aux = aux->next;
            }
            if(count <= size){
                string search = aux->getData().getTitle();
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
    void deleteInput(News pArray[]) {///// borra segun los elementos en la lista
        Node* aux = cursor;
        int arraySize = sizeof(pArray) / sizeof(pArray[0]);
        if(cursor != nullptr){
            for (int i = 1; i <= size; i++) {
                for (int j = 0; j < arraySize; j++){
                    if(searchWordInNode(pArray[j].getContent(), aux)){
                        removeIndex(nodePosition(aux->elem));
                    }
                }
                aux = aux->next; 
            } 
        } 
    }
     //
    void inputRelevance(News pArray[]) {///// ordena por relevancia
        Node* aux = cursor;
        int arraySize = sizeof(pArray) / sizeof(pArray[0]);
        
        if(cursor != nullptr){
            for (int i = 0; i <= size; i++) {
                for (int j = 0; j < arraySize; j++){
                    if(searchWordInNode(pArray[j].getContent(), aux)){
                        addToFront(aux->elem);
                    }
                }
                aux = aux->next; 
            } 
        }
    }
    //
    void reubicate(int pPosition, string moveTo ){
        int num;
        News aux = find(pPosition);
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
            placeInPosition(aux, where, pPosition);
        }
        else{
            int where = pPosition + num;
            if (where > size){
                where = size;       
            }
            placeInPosition(aux, where, pPosition);
        }
    }
    //
    void placeInPosition(News pNews, int pNew, int pPrevious){
        Node* aux = new Node(pNews);
        News removed;
        if(size == 0 ){
            cout << "empty list" << endl;
        }
        else if (cursor == nullptr){
            cursor = aux;
        }
        else {
            removed = removeIndex(pPrevious);
            addToIndex(removed, pNew);
        }
    }
};

int main() {
    CircularLinkedList lista;
    lista.showPositions();
    lista.countNodes();
    lista.showPositions();
    cout << lista.back().getTitle() << endl;
    cout << lista.front().getTitle() << endl;
    cout<< endl;
    cout<< endl;
};
#endif