#ifndef TMPMYSTACK_H
#define TMPMYSTACK_H

#include <iostream>
#include "tmpmylist.h"

using namespace std;

//template<typename nodetype>
//class myTMPNode
//{
//public:
//    myTMPNode();
//    myTMPNode(const nodetype &n);
//    ~myTMPNode();
//    void setLink(myTMPNode *next);
//    void setNum(const nodetype &n);
//    myTMPNode *getLink();
//    nodetype getNum();
//private:
//    nodetype num;
//    myTMPNode *nextNode = nullptr;
//};

template<typename nodetype>
class myTMPStack
{
public:
    myTMPStack();
    myTMPStack(const int &n);
    ~myTMPStack();
    void push(const nodetype &el);
    myTMPNode<nodetype> *pull();
    myTMPNode<nodetype> *getTop();
    void printall();
private:
    int maxnodes = 10;
    int numnodes = 0;
    myTMPNode<nodetype> *top = nullptr;
};

template<typename nodetype>
myTMPStack<nodetype>::myTMPStack()
{
    cout << "*myStack construcror*" << endl;
}

template<typename nodetype>
myTMPStack<nodetype>::myTMPStack(const int &n)
{
    cout << "*myStack construcror with " << n << " elements*" << endl;
    maxnodes = n;

    myTMPNode<nodetype> *node = nullptr;
    top = node;
}

template<typename nodetype>
myTMPStack<nodetype>::~myTMPStack()
{
    cout << "*myStack destructor*" << endl;

    for (int i = numnodes; i > 0; i--)
        pull();

    cout << "end of destruct" << endl;
}

template<typename nodetype>
void myTMPStack<nodetype>::push(const nodetype &el)
{
    if (numnodes < maxnodes)
    {
        myTMPNode<nodetype> *node = new myTMPNode<nodetype>(el);
        node->setLink(top);
        top = node;

        numnodes++;
    }
}

template<typename nodetype>
myTMPNode<nodetype> *myTMPStack<nodetype>::pull()
{
    if (numnodes > 0)
    {
        myTMPNode<nodetype> *node = top;
        top = node->getLink();        

        numnodes--;

        return node;
    }
    return nullptr;
}

template<typename nodetype>
myTMPNode<nodetype> *myTMPStack<nodetype>::getTop()
{
    return top;
}

template<typename nodetype>
void myTMPStack<nodetype>::printall()
{
    myTMPNode<nodetype> *node = top;

    for (int i = 0; i < numnodes; i++)
    {
         cout << "element[" << i << "] = " << node->getNum() << endl;
         node = node->getLink();
    }
}

#endif // TMPMYSTACK_H
