#ifndef TMPTREE_H
#define TMPTREE_H

#include <iostream>
#include "tmpmystack.h"

using namespace std;

template<typename nodetype>
class myTMPTreeNode
{
public:
    myTMPTreeNode();
    myTMPTreeNode(const nodetype &n);
    ~myTMPTreeNode();
    void setLeftLink(myTMPTreeNode *next);
    void setRightLink(myTMPTreeNode *next);
    void setPrevLink(myTMPTreeNode *prev);
    myTMPTreeNode *getLeftLink();
    myTMPTreeNode *getRightLink();
    myTMPTreeNode *getPrevLink();
    void setNum(const nodetype &n);
    nodetype getNum();
private:
    nodetype num;
    myTMPTreeNode *nextLeftNode = nullptr;
    myTMPTreeNode *nextRightNode = nullptr;    
};

typedef enum
{
    LEFT,
    RIGHT
} treev;

template<typename nodetype>
struct stackst
{
    myTMPTreeNode<nodetype> *node;
    mutable treev status;
};

typedef enum
{
    START,
    TOLEFT,
    TORIGHT,
    PUSHLEFT,
    PUSHRIGHT,
    PULLUP,
    PRINT,
    STOP
} events;

template<typename nodetype>
class myTMPTree
{
public:
    myTMPTree();
    myTMPTree(const uint &n);
    ~myTMPTree();
    void append(const nodetype &el);    
    void remove(const nodetype &nm);
    myTMPTreeNode<nodetype> *searchsimm(const nodetype &el);
    myTMPTreeNode<nodetype> *searchheight(const nodetype &el);
    myTMPTreeNode<nodetype> *searchwidth(const nodetype &el);
    void printall();
private:
    uint maxnodes = 50;
    uint numnodes = 0;
    myTMPTreeNode<nodetype> *head = nullptr;
    myTMPTreeNode<nodetype> *current = nullptr;

    myTMPStack<stackst<nodetype>> *stack;
};

template<typename nodetype>
myTMPTree<nodetype>::myTMPTree()
{
    cout << "*myTree construcror*" << endl;
}

template<typename nodetype>
myTMPTree<nodetype>::myTMPTree(const uint &n)
{
    cout << "*myTree construcror with " << n << " elements*" << endl;
    maxnodes = n;
}

template<typename nodetype>
myTMPTree<nodetype>::~myTMPTree()
{
    cout << "*myTree destructor*" << endl;

//    myTMPTreeNode<nodetype> *node = end;
//    myTMPTreeNode<nodetype> *curnode = 0x0;
//    while (node)
//    {
//        curnode = node;
//        node = node->getPrevLink();

//        delete curnode;
//    }

    cout << "end of destruct" << endl;
}

template<typename nodetype>
void myTMPTree<nodetype>::append(const nodetype &el)
{
    if (numnodes < maxnodes)
    {
        if (!head)
        {
            head = new myTMPTreeNode<nodetype>(el);
            numnodes++;
        }
        else
        {
            if (current->getNum() > el)
            {
                if (!current->getLeftLink())
                {
                    myTMPTreeNode<nodetype> *node = new myTMPTreeNode<nodetype>(el);
                    current->setLeftLink(node);
                    numnodes++;

                    return;
                }
                else
                {
                    current = current->getLeftLink();
                    append(el);
                }
            }
            else if (current->getNum() < el)
            {
                if (!current->getRightLink())
                {
                    myTMPTreeNode<nodetype> *node = new myTMPTreeNode<nodetype>(el);
                    current->setRightLink(node);
                    numnodes++;

                    return;
                }
                else
                {
                    current = current->getRightLink();
                    append(el);                    
                }
            }
        }

        current = head;
    }
}

template<typename nodetype>
void myTMPTree<nodetype>::remove(const nodetype &nm)
{
    /* Добавить поиск элемента, и заменить указатель на голову на указатель на найденный элемент */
    if (numnodes < maxnodes)
    {
        myTMPTreeNode<nodetype> *link = searchsimm(nm);

        if (link->getNum() == nm)
        {
            myTMPTreeNode<nodetype> *el = link;
            myTMPTreeNode<nodetype> *prev = el;
            myTMPTreeNode<nodetype> *cur = nullptr;

            if (prev->getLeftLink())
            {
                 cur = prev->getLeftLink();

                 while(cur->getRightLink())
                 {
                     prev = cur;
                     cur = cur->getRightLink();
                 }

                 if (prev != el)
                     prev->setRightLink(cur->getLeftLink());
                  else
                    prev->setLeftLink(cur->getLeftLink());

                 cur->setLeftLink(el->getLeftLink());                 
                 cur->setRightLink(el->getRightLink());                 

                 *el = *cur;

                 delete cur;
            }
            else if (prev->getRightLink())
            {
                cur = prev->getRightLink();

                while(cur->getLeftLink())
                {
                    prev = cur;
                    cur = cur->getLeftLink();
                }

                if (prev != el)
                    prev->setLeftLink(cur->getRightLink());
                 else
                   prev->setRightLink(cur->getRightLink());

                cur->setLeftLink(el->getLeftLink());
                cur->setRightLink(el->getRightLink());

                *el = *cur;

                delete cur;
            }
        }
    }
}

template<typename nodetype>
myTMPTreeNode<nodetype> *myTMPTree<nodetype>::searchsimm(const nodetype &el)
{
    stack = new myTMPStack<stackst<nodetype>>;
    stackst<nodetype> elst = {head, LEFT};
    myTMPNode<stackst <nodetype>> *node = nullptr;
    events EVENT = TOLEFT;
    uint curnum = 0;

    while (EVENT != STOP)
    {
        switch(EVENT)
        {
            case (START):
                curnum++;
                if (elst.node->getNum() != el)
                    EVENT = TORIGHT;
                else
                    EVENT = STOP;
                break;
            case (TOLEFT):
                if (elst.node->getLeftLink())
                    EVENT = PUSHLEFT;
                else
                    EVENT = START;
                break;
            case (TORIGHT):
                if (elst.node->getRightLink())
                    EVENT = PUSHRIGHT;
                else if (curnum == numnodes)
                    EVENT = STOP;
                else
                    EVENT = PULLUP;
                break;
            case (PUSHLEFT):
                stack->push(elst);
                elst = {elst.node->getLeftLink(), LEFT};
                EVENT = TOLEFT;
                break;
            case (PUSHRIGHT):
                stack->push(elst);
                elst = {elst.node->getRightLink(), RIGHT};
                EVENT = TOLEFT;
                break;
            case (PULLUP):
                node = stack->pull();
                if (elst.status == LEFT)
                {
                    elst = node->getNum();
                    EVENT = START;
                }
                else
                {
                   elst = node->getNum();
                   EVENT = PULLUP;
                }
                break;
            default:
                return nullptr;
                break;
        }
    }

    delete stack;

    if (elst.node->getNum() == el)
        return elst.node;
    else
        return nullptr;
}

template<typename nodetype>
myTMPTreeNode<nodetype> *myTMPTree<nodetype>::searchheight(const nodetype &el)
{
    stack = new myTMPStack<stackst<nodetype>>;
    stackst<nodetype> elst = {head, LEFT};
    myTMPNode<stackst <nodetype>> *node = nullptr;
    events EVENT = TOLEFT;
    uint curnum = 0;

    while (EVENT != STOP)
    {
        switch(EVENT)
        {
            case (START):
                curnum++;
                if (elst.node->getNum() != el)
                    EVENT = PULLUP;
                else
                    EVENT = STOP;
                break;
            case (TOLEFT):
                if (elst.node->getLeftLink())
                    EVENT = PUSHLEFT;
                else
                    EVENT = TORIGHT;
                break;
            case (TORIGHT):
                if (elst.node->getRightLink())
                    EVENT = PUSHRIGHT;
                else if (curnum == numnodes)
                    EVENT = STOP;
                else
                    EVENT = START;
                break;
            case (PUSHLEFT):
                stack->push(elst);
                elst = {elst.node->getLeftLink(), LEFT};
                EVENT = TOLEFT;
                break;
            case (PUSHRIGHT):
                stack->push(elst);
                elst = {elst.node->getRightLink(), RIGHT};
                EVENT = TOLEFT;
                break;
            case (PULLUP):
                node = stack->pull();
                if (elst.status == LEFT)
                {
                    elst = node->getNum();
                    EVENT = TORIGHT;
                }
                else
                {
                   elst = node->getNum();
                   EVENT = START;
                }
                break;
            default:
                return nullptr;
                break;
        }
    }

    delete stack;

    if (elst.node->getNum() == el)
        return elst.node;
    else
        return nullptr;
}

/*
 *В алгоритме:
 *1. Принимаем номер искомого элемента, инициализируем стек, структуру элемента стека с головой дерева и статусом, и счётчик количества элементов.
 *Перебераем элементвы в машинесостояний:
 *2. Берём элемент
 *3. Если левая ссылка существует, то пихаем его в стек, перемещаясь на левый дочерний, повторяем (2).
 *4. Если не существует, аналогично проверяем правую, и если она существует, повторяем (2).
 *5. Если не существуют обе ссылки и элемент не соответствует, переносимся на уровень выше, вытаскиваем элемент из стека.
 *6. Если при этом статус текущего элемента соответствует "левой" дочерней ветке вытащенного из стека, выбираем правую дочернюю ветку элемента из стека и всё повторяем.
 *7. Если текущий элемент уже со статусом "правый", то снова переносимся на уровень выше и повторяем (6).
 *8. Если найден искомый элемент
 *
 */

template<typename nodetype>
myTMPTreeNode<nodetype> *myTMPTree<nodetype>::searchwidth(const nodetype &el)
{
    stack = new myTMPStack<stackst<nodetype>>;    
    stackst<nodetype> elst = {head, LEFT};
    myTMPNode<stackst <nodetype>> *node = nullptr;
    events EVENT = START;
    uint curnum = 0;

    while (EVENT != STOP)
    {
        switch(EVENT)
        {
            case (START):
                curnum++;
                if (elst.node->getNum() != el)
                    EVENT = TOLEFT;
                else
                    EVENT = STOP;
                break;
            case (TOLEFT):
                if (elst.node->getLeftLink())
                    EVENT = PUSHLEFT;
                else
                    EVENT = TORIGHT;
                break;
            case (TORIGHT):
                if (elst.node->getRightLink())
                    EVENT = PUSHRIGHT;
                else if (curnum == numnodes)
                    EVENT = STOP;
                else
                    EVENT = PULLUP;                
                break;
            case (PUSHLEFT):
                stack->push(elst);
                elst = {elst.node->getLeftLink(), LEFT};
                EVENT = START;
                break;
            case (PUSHRIGHT):
                stack->push(elst);
                elst = {elst.node->getRightLink(), RIGHT};
                EVENT = START;
                break;
            case (PULLUP):
                node = stack->pull();
                if (elst.status == LEFT)
                {
                    elst = node->getNum();
                    EVENT = TORIGHT;
                }
                else
                {
                   elst = node->getNum();
                   EVENT = PULLUP;                   
                }
                break;
            default:
                return nullptr;
                break;
        } 
    }

    delete stack;

    if (elst.node->getNum() == el)
        return elst.node;
    else
        return nullptr;;
}

template<typename nodetype>
void myTMPTree<nodetype>::printall()
{
//    myTMPTreeNode<nodetype> *node = head->getNextLink();

//    for (int i = 1; i <= numnodes; i++)
//    {
//         cout << "element[" << i << "] = " << node->getNum() << endl;
//         node = node->getNextLink();
//    }
}

template<typename nodetype>
myTMPTreeNode<nodetype>::myTMPTreeNode()
{
    cout << "*myNode construcror* address = " << this << endl;
}

template<typename nodetype>
myTMPTreeNode<nodetype>::myTMPTreeNode(const nodetype &n)
{
    cout << "*myNode construcror* address = " << this << " num = " << n << endl;
    num = n;    
}

template<typename nodetype>
myTMPTreeNode<nodetype>::~myTMPTreeNode()
{
    cout << "*myNode destrucror* address = " << this << " num = " << this->getNum() << endl;

    nextLeftNode = nullptr;
    nextRightNode = nullptr;
}

template<typename nodetype>
void myTMPTreeNode<nodetype>::setLeftLink(myTMPTreeNode *next)
{
    nextLeftNode = next;
}

template<typename nodetype>
void myTMPTreeNode<nodetype>::setRightLink(myTMPTreeNode *next)
{
    nextRightNode = next;
}

//template<typename nodetype>
//void myTMPTreeNode<nodetype>::setPrevLink(myTMPTreeNode *prev)
//{
//    //prevNode = prev;
//}

template<typename nodetype>
void myTMPTreeNode<nodetype>::setNum(const nodetype &n)
{
    num = n;
}

template<typename nodetype>
myTMPTreeNode<nodetype> *myTMPTreeNode<nodetype>::getLeftLink()
{
    return nextLeftNode;
}

template<typename nodetype>
myTMPTreeNode<nodetype> *myTMPTreeNode<nodetype>::getRightLink()
{
    return nextRightNode;
}

template<typename nodetype>
myTMPTreeNode<nodetype> *myTMPTreeNode<nodetype>::getPrevLink()
{
    //return prevNode;
}

template<typename nodetype>
nodetype myTMPTreeNode<nodetype>::getNum()
{
    return num;
}


#endif // TMPDOUBLELINKLIST_H
