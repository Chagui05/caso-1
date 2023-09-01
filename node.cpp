#ifndef _NODE_
#define _NODE_ 1
#include <iostream>
#include <string>
#include "news.cpp"

using namespace std;

struct Node {
    int elem;
    Node* next;
    News* news;

    Node() : next(nullptr) {};

    Node(int pValue) : elem(pValue), next(nullptr) {};

    Node(News &value) {
        news = &value;
        next = nullptr;
    };

    News* getData() {return news; };
};

#endif