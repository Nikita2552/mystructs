#ifndef TMPDOUBLELINKLIST_H
#define TMPDOUBLELINKLIST_H

#include <iostream>

using namespace std;

template<typename nodetype>
class myTMPDoubleNode
{
public:
    myTMPDoubleNode();
    myTMPDoubleNode(const nodetype &n);
    ~myTMPDoubleNode();
    void setNextLink(myTMPDoubleNode *next);
    void setPrevLink(myTMPDoubleNode *prev);
    myTMPDoubleNode *getNextLink();
    myTMPDoubleNode *getPrevLink();
    void setNum(const nodetype &n);
    nodetype getNum();
private:
    nodetype num;
    myTMPDoubleNode *nextNode = nullptr;
    myTMPDoubleNode *prevNode = nullptr;
};

template<typename nodetype>
class myTMPDoubleLinkList
{
public:
    myTMPDoubleLinkList();
    myTMPDoubleLinkList(const uint &n);
    ~myTMPDoubleLinkList();
    void append(const nodetype &el);
    void insert(const uint &nm, const nodetype &el);
    void remove(const uint &nm);
    void printall();
private:
    uint maxnodes = 10;
    uint numnodes = 0;
    myTMPDoubleNode<nodetype> *head = nullptr;
    myTMPDoubleNode<nodetype> *end = nullptr;
};

template<typename nodetype>
myTMPDoubleLinkList<nodetype>::myTMPDoubleLinkList()
{
    cout << "*myList construcror*" << endl;
}

template<typename nodetype>
myTMPDoubleLinkList<nodetype>::myTMPDoubleLinkList(const uint &n)
{
    cout << "*myList construcror with " << n << " elements*" << endl;
    maxnodes = n;

    head = new myTMPDoubleNode<nodetype>();
    end = new myTMPDoubleNode<nodetype>();

    head->setNextLink(end);
    end->setPrevLink(head);
}

template<typename nodetype>
myTMPDoubleLinkList<nodetype>::~myTMPDoubleLinkList()
{
    cout << "*myList destructor*" << endl;

    myTMPDoubleNode<nodetype> *node = end;
    myTMPDoubleNode<nodetype> *curnode = 0x0;
    while (node)
    {
        curnode = node;
        node = node->getPrevLink();

        delete curnode;
    }

    cout << "end of destruct" << endl;
}

template<typename nodetype>
void myTMPDoubleLinkList<nodetype>::append(const nodetype &el)
{
    if (numnodes < maxnodes)
    {
        myTMPDoubleNode<nodetype> *node = new myTMPDoubleNode<nodetype>(el);

        myTMPDoubleNode<nodetype> *leftNode = end->getPrevLink();

        leftNode->setNextLink(node);
        node->setPrevLink(leftNode);

        node->setNextLink(end);
        end->setPrevLink(node);

        numnodes++;
    }
}

template<typename nodetype>
void myTMPDoubleLinkList<nodetype>::insert(const uint &nm, const nodetype &el)
{
    if ((nm < numnodes) && (nm > 0))
    {
        myTMPDoubleNode<nodetype> *leftNode = head;

       for (uint i = 0; i < nm; i++)
            leftNode = leftNode->getNextLink();

       myTMPDoubleNode<nodetype> *rightNode = leftNode->getNextLink();

       myTMPDoubleNode<nodetype> *newNode = new myTMPDoubleNode<nodetype>(el);
       newNode->setNextLink(rightNode);
       leftNode->setNextLink(newNode);

       newNode->setPrevLink(leftNode);
       rightNode->setPrevLink(newNode);

       numnodes++;
    }
}

template<typename nodetype>
void myTMPDoubleLinkList<nodetype>::remove(const uint &nm)
{
    if ((nm < numnodes) && (nm > 0))
    {
        myTMPDoubleNode<nodetype> *leftNode = head;

       for (uint i = 0; i < nm; i++)
            leftNode = leftNode->getNextLink();

       myTMPDoubleNode<nodetype> *newNode = leftNode->getNextLink();
       myTMPDoubleNode<nodetype> *rightNode = newNode->getNextLink();

       leftNode->setNextLink(newNode->getNextLink());
       rightNode->setPrevLink(newNode->getPrevLink());

       delete newNode;

       numnodes--;
    }
}

template<typename nodetype>
void myTMPDoubleLinkList<nodetype>::printall()
{
    myTMPDoubleNode<nodetype> *node = head->getNextLink();

    for (uint i = 1; i <= numnodes; i++)
    {
         cout << "element[" << i << "] = " << node->getNum() << endl;
         node = node->getNextLink();
    }
}

template<typename nodetype>
myTMPDoubleNode<nodetype>::myTMPDoubleNode()
{
    cout << "*myNode construcror* address = " << this << endl;
}

template<typename nodetype>
myTMPDoubleNode<nodetype>::myTMPDoubleNode(const nodetype &n)
{
    cout << "*myNode construcror* address = " << this << " num = " << n << endl;
    num = n;
    nextNode = nullptr;
}

template<typename nodetype>
myTMPDoubleNode<nodetype>::~myTMPDoubleNode()
{
    cout << "*myNode destrucror* address = " << this << " num = " << this->getNum() << endl;
}

template<typename nodetype>
void myTMPDoubleNode<nodetype>::setNextLink(myTMPDoubleNode *next)
{
    nextNode = next;
}

template<typename nodetype>
void myTMPDoubleNode<nodetype>::setPrevLink(myTMPDoubleNode *prev)
{
    prevNode = prev;
}

template<typename nodetype>
void myTMPDoubleNode<nodetype>::setNum(const nodetype &n)
{
    num = n;
}

template<typename nodetype>
myTMPDoubleNode<nodetype> *myTMPDoubleNode<nodetype>::getNextLink()
{
    return nextNode;
}

template<typename nodetype>
myTMPDoubleNode<nodetype> *myTMPDoubleNode<nodetype>::getPrevLink()
{
    return prevNode;
}

template<typename nodetype>
nodetype myTMPDoubleNode<nodetype>::getNum()
{
    return num;
}


#endif // TMPDOUBLELINKLIST_H
