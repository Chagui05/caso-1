#ifndef _NODE_
#define _NODE_ 1
#include <iostream>
#include <string>
#include "news.cpp"
#include "list.cpp"

using namespace std;

struct Node {
    Node* next;
    News elem;

    Node() : next(nullptr) {};

    Node(News value) {
        elem = value;
        next = nullptr;
    };

    News getData() {return elem; };

};

#endif