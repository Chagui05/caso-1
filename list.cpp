#ifndef _LIST_
#define _LIST_ 1
#include <iostream>
#include <string>
#include "node.cpp"
/*
por ahora estoy usando Integers para almacernar los datos del nodo
en un futuro posiblemente eso cambia a una clase llamada Noticia o titular
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
    int searchNode(int pElem){
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
    /*
    void searchWord(string pWord){ 
        Node* aux = cursor;
        if( cursor != nullptr){
            for(int count = 1 ; count <= size ; count++){
                size_t pos = aux->elem.find(pWord);
                if(pos != string::npos){                                    FUNCION NO DISPONIBLE POR EL MOMENTO
                    cout << aux->elem << " " << pos << endl;                cambiar de void a lo que ocupe, ademas estoy buscando con ints, luego cambiara a strings posiblemente
                    return;
                }
                aux = aux->next;
            }
        }   
        else {cout << "Element not found or empty list" << endl;}    
    }
    */
    void inputRelevance(int pArray[]) {
        int *arrayPointer = &pArray[0];
        Node *aux = cursor;
        
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