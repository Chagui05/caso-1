#ifndef _NODE_
#define _NODE_ 1
#include <iostream>
#include <string>

using namespace std;

struct Node {
    int elem;
    Node* next;
    Node() : next(nullptr) {};

    Node(int pValue) : elem(pValue), next(nullptr) {};
};

#endif