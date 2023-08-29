#include <iostream>
#include <string>
using namespace std;

//para crear nodos
class Node{
private:
string elem;
Node* next;
friend class circularList;
};

class circularList{  
private:
Node* cursor;

public:
    circularList() {
        cursor = NULL;
    }
    ~circularList() {             
        while (!empty()) remove(); 
    }
    bool empty() const{
        return cursor == NULL;
    }
    const string& back() const{        // los string posiblemente cambien por si los archivos que nos pase el profe son clases 
        return cursor->elem; 
    }
    const string& front() const{
        return cursor->next->elem;
    }
    void advance(){
        cursor = cursor->next;
    }
    void add(const string& elem){
        Node* aux = new Node;
        aux->elem = elem;
        if(cursor == NULL){
            aux->next = aux;
            cursor = aux;
        }
        else{
            aux->next = cursor->next;
            cursor->next = aux;
        }
    }
    void remove(){
        Node* old = cursor->next;
        if (old == cursor){
        cursor == NULL;
        }
        else{ 
        cursor->next = old->next;
        }
        delete old;
    }
    int countNodes(){
        Node* aux = cursor;
        int count = 0;

        if(aux != NULL){
            count++;
            aux = aux->next;
        }
        while(aux!=cursor){
            count++;
            aux = aux->next;
        }
        cout << count << endl;
        return count;
    }

    void display() {
        Node* aux = cursor;
        if(aux == NULL){
            cout << "**Empty list**" <<endl;
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

    string searchNode(string nodo){
    cursor;
    while(cursor->elem != nodo){            // solucionar que no se encicle si no encuentra valor
        advance();
    }
    cout << back() << endl;
    return back(); 
    }
    

};

int main ()
{
    circularList lista;
    lista.add("hola");
    lista.add("a");
    lista.add("b");
    lista.add("c");
    lista.add("d");
    lista.countNodes();
    lista.display();
    cout << "search" << endl;
    lista.searchNode("c");
    }