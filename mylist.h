#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>

using namespace std;

class myNode
{
public:
    myNode();
    myNode(const int &n);
    ~myNode();
    void setLink(myNode *next);
    void setNum(const int &n);
    myNode *getLink();
    int getNum();
private:
    int num = 0;
    myNode *nextNode = nullptr;
};

class myList
{
public:
    myList();
    myList(const int &n);
    ~myList();
    void append(const int &el);
    void insert(const int &nm, const int &el);
    void remove(const int &nm);
private:
    int maxnodes = 10;
    int numnodes = 0;
    myNode *head = nullptr;
    myNode *end = nullptr;
};

#endif // MYLIST_H
