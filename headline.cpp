#ifndef _HEADLINE_
#define _HEADLINE_ 1
#include <iostream>
#include <string>

using namespace std;

class Headline {
    private: 
        string title;
        string content;

    public:
        Headline(string pTitle, string pContent) {
            title = pTitle;
            content = pContent;
        }

        string getTitle() {
            return title;
        }

        string getContent() {
            return content;
        }
};

#endif