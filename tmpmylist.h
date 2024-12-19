#ifndef TMPMYLIST_H
#define TMPMYLIST_H

#include <iostream>

using namespace std;

template<typename nodetype>
class myTMPNode
{
public:
    myTMPNode();
    myTMPNode(const nodetype &n);
    ~myTMPNode();
    void setLink(myTMPNode *next);
    void setNum(const nodetype &n);
    myTMPNode *getLink();
    nodetype getNum();
private:
    nodetype num;
    myTMPNode *nextNode = nullptr;
};

template<typename nodetype>
class myTMPList
{
public:
    myTMPList();
    myTMPList(const int &n);
    ~myTMPList();
    void append(const nodetype &el);
    void insert(const int &nm, const nodetype &el);
    void remove(const int &nm);
    void printall();
private:
    int maxnodes = 10;
    int numnodes = 0;
    myTMPNode<nodetype> *head = nullptr;
    myTMPNode<nodetype> *end = nullptr;
};

template<typename nodetype>
myTMPList<nodetype>::myTMPList()
{
    cout << "*myList construcror*" << endl;
}

template<typename nodetype>
myTMPList<nodetype>::myTMPList(const int &n)
{
    cout << "*myList construcror with " << n << " elements*" << endl;
    maxnodes = n;

    myTMPNode<nodetype> *node = new myTMPNode<nodetype>();
    head = node;
    end = node;

}

template<typename nodetype>
myTMPList<nodetype>::~myTMPList()
{
    cout << "*myList destructor*" << endl;

    for (int i = numnodes; i >= 0; i--)
        remove(i);

    delete head;

    cout << "end of destruct" << endl;
}

template<typename nodetype>
void myTMPList<nodetype>::append(const nodetype &el)
{
    if (numnodes < maxnodes)
    {
        myTMPNode<nodetype> *node = new myTMPNode<nodetype>(el);
        end->setLink(node);
        end = node;

        numnodes++;
    }
}

template<typename nodetype>
void myTMPList<nodetype>::insert(const int &nm, const nodetype &el)
{
    if ((nm < numnodes) && (nm >= 0))
    {
        myTMPNode<nodetype> *node = head;

       for (int i = 0; i < nm; i++)
            node = node->getLink();

       myTMPNode<nodetype> *newNode = new myTMPNode<nodetype>(el);
       newNode->setLink(node->getLink());
       node->setLink(newNode);

       numnodes++;
    }
}

template<typename nodetype>
void myTMPList<nodetype>::remove(const int &nm)
{
    if ((nm < numnodes) && (nm >= 0))
    {
        myTMPNode<nodetype> *node = head;

       for (int i = 0; i < nm; i++)
            node = node->getLink();

       myTMPNode<nodetype> *newNode = node->getLink();
       node->setLink(newNode->getLink());

       delete newNode;

       numnodes--;
    }
}

template<typename nodetype>
void myTMPList<nodetype>::printall()
{
    myTMPNode<nodetype> *node = head->getLink();

    for (int i = 0; i < numnodes; i++)
    {
         cout << "element[" << i << "] = " << node->getNum() << endl;
         node = node->getLink();
    }
}

template<typename nodetype>
myTMPNode<nodetype>::myTMPNode()
{
    cout << "*myNode construcror* address = " << this << endl;
}

template<typename nodetype>
myTMPNode<nodetype>::myTMPNode(const nodetype &n)
{
//    cout << "*myNode construcror* address = " << this << " num = " << n << endl;
    num = n;
    nextNode = nullptr;
}

template<typename nodetype>
myTMPNode<nodetype>::~myTMPNode()
{
    cout << "*myNode destrucror* address = " << this << " num = " << this->getNum() << endl;
}

template<typename nodetype>
void myTMPNode<nodetype>::setLink(myTMPNode *next)
{
    nextNode = next;
}

template<typename nodetype>
void myTMPNode<nodetype>::setNum(const nodetype &n)
{
    num = n;
}

template<typename nodetype>
myTMPNode<nodetype> *myTMPNode<nodetype>::getLink()
{
    return nextNode;
}

template<typename nodetype>
nodetype myTMPNode<nodetype>::getNum()
{
    return num;
}

#endif // MYLIST_H
