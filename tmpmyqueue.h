#ifndef TMPMYQUEUE_H
#define TMPMYQUEUE_H

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
class myTMPQueue
{
public:
    myTMPQueue();
    myTMPQueue(const int &n);
    ~myTMPQueue();
    void enqueue(const nodetype &el);
    void enqueue(const myTMPNode<nodetype> &tmpnode);
    myTMPNode<nodetype>* dequeue();
    void printall();
private:
    int maxnodes = 10;
    int numnodes = 0;
    myTMPNode<nodetype> *top = nullptr;
    myTMPNode<nodetype> *fin = nullptr;
};

template<typename nodetype>
myTMPQueue<nodetype>::myTMPQueue()
{
    cout << "*myList construcror*" << endl;
}

template<typename nodetype>
myTMPQueue<nodetype>::myTMPQueue(const int &n)
{
    cout << "*myList construcror with " << n << " elements*" << endl;
    maxnodes = n;

    top = nullptr;
    fin = nullptr;
}

template<typename nodetype>
myTMPQueue<nodetype>::~myTMPQueue()
{
    cout << "*myList destructor*" << endl;

    int curnum = numnodes;
    for (int i = 0; i < curnum; i++)
        delete this->dequeue();

    cout << "end of destruct" << endl;
}

template<typename nodetype>
void myTMPQueue<nodetype>::enqueue(const nodetype &el)
{
    if (numnodes < maxnodes)
    {
        myTMPNode<nodetype> *node = new myTMPNode<nodetype>(el);
        node->setLink(top);

        if (top == nullptr)
            fin = node;
        top = node;

        numnodes++;
    }
}

template<typename nodetype>
void myTMPQueue<nodetype>::enqueue(const myTMPNode<nodetype> &tmpnode)
{
    if (numnodes < maxnodes)
    {
        tmpnode->setLink(top);

        if (top == nullptr)
            fin = tmpnode;
        top = tmpnode;

        numnodes++;
    }
}

template<typename nodetype>
myTMPNode<nodetype>* myTMPQueue<nodetype>::dequeue()
{
    myTMPNode<nodetype> *node = top;
    if (numnodes > 1)
    {
        while(node->getLink() != fin)
            node = node->getLink();

       myTMPNode<nodetype> *newNode = fin;
       fin = node;

       numnodes--;

       return newNode;
    }
    else
    {
        top = nullptr;
        fin = nullptr;

        numnodes--;

        return node;
    }
}

template<typename nodetype>
void myTMPQueue<nodetype>::printall()
{
    myTMPNode<nodetype> *node = top;

    for (int i = 0; i < numnodes; i++)
    {
         cout << "element[" << i << "] = " << node->getNum() << endl;
         node = node->getLink();
    }
}

//template<typename nodetype>
//myTMPNode<nodetype>::myTMPNode()
//{
//    cout << "*myNode construcror*" << endl;
//}

//template<typename nodetype>
//myTMPNode<nodetype>::myTMPNode(const nodetype &n)
//{
//    cout << "*myNode construcror*" << endl;
//    num = n;
//    nextNode = nullptr;
//}

//template<typename nodetype>
//myTMPNode<nodetype>::~myTMPNode()
//{
//    cout << "*myNode destrucror*" << endl;
//}

//template<typename nodetype>
//void myTMPNode<nodetype>::setLink(myTMPNode *next)
//{
//    nextNode = next;
//}

//template<typename nodetype>
//void myTMPNode<nodetype>::setNum(const nodetype &n)
//{
//    num = n;
//}

//template<typename nodetype>
//myTMPNode<nodetype> *myTMPNode<nodetype>::getLink()
//{
//    return nextNode;
//}

//template<typename nodetype>
//nodetype myTMPNode<nodetype>::getNum()
//{
//    return num;
//}

#endif // TMPMYQUEUE_H
