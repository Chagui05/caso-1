#ifndef _NEWS_
#define _NEWS_ 1
#include <iostream>
#include <string>

using namespace std;

class News {
    private: 
        string title;
        string content;

    public:
        News(string pTitle, string pContent) {
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