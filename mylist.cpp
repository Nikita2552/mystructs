#include "mylist.h"

myList::myList()
{
    cout << "*myList construcror*" << endl;
}

myList::myList(const int &n)
{
    cout << "*myList construcror with " << n << " elements*" << endl;
    maxnodes = n;

    myNode *node = new myNode(0);
    head = node;
    end = node;

}

myList::~myList()
{
    cout << "*myList destructor*" << endl;

    for (int i = numnodes; i >= 0; i--)
        remove(i);

    delete head;

    cout << "end of destruct" << endl;
}

void myList::append(const int &el)
{
    if (numnodes < maxnodes)
    {
        myNode *node = new myNode(el);
        end->setLink(node);
        end = node;

        numnodes++;
    }
}

void myList::insert(const int &nm, const int &el)
{
    if ((nm < numnodes) && (nm > 0))
    {
        myNode *node = head;

       for (int i = 0; i < nm; i++)
            node = node->getLink();

       myNode *newNode = new myNode(el);
       newNode->setLink(node->getLink());
       node->setLink(newNode);

       numnodes++;
    }
}

void myList::remove(const int &nm)
{
    if ((nm < numnodes) && (nm > 0))
    {
        myNode *node = head;

       for (int i = 0; i < nm; i++)
            node = node->getLink();

       myNode *newNode = node->getLink();
       node->setLink(newNode->getLink());

       delete newNode;

       numnodes--;
    }
}

myNode::myNode()
{
    cout << "*myNode construcror*" << endl;
}

myNode::myNode(const int &n)
{
    cout << "*myNode construcror*" << endl;
    num = n;
    nextNode = nullptr;
}

myNode::~myNode()
{
    cout << "*myNode destrucror*" << endl;
}

void myNode::setLink(myNode *next)
{
    nextNode = next;
}

void myNode::setNum(const int &n)
{
    num = n;
}

myNode *myNode::getLink()
{
    return nextNode;
}

int myNode::getNum()
{
    return num;
}
