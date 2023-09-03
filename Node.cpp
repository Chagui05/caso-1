#ifndef _NODE_
#define _NODE_ 1
#include <iostream>
#include <string>
#include "News.cpp"

using namespace std;

struct Node {
    News* elem;
    Node* next;

    Node() : elem(nullptr) , next(nullptr) {};

    Node(News* pElem) : elem(pElem), next(nullptr) {}

    News* getData() {return elem; };

};

#endif