#include <iostream>
#include "mylist.h"
#include "tmpmylist.h"
#include "tmpmystack.h"
#include "tmpmyqueue.h"
#include "tmpdoublelinklist.h"
#include "tmptree.h"

using namespace std;

void mylistmain()
{
    myList test(7);
    test.append(1);
    test.append(5);
    test.append(3);

    test.insert(1, 7);

    test.remove(0);
}

void tmpmylistmain()
{
    myTMPList<int> test(7);
    test.append(1);
    test.append(5);
    test.append(3);

    test.insert(1, 7);

    test.remove(0);

    test.printall();
}

void tmpmylistmainst()
{
    myTMPList<string> test(7);
    test.append("hello");
    test.append("this");
    test.append("perfect");

    test.insert(1, "world");

    test.remove(0);

    test.printall();
}

void tmpmystackmainst()
{
    myTMPStack<int> test(7);
    test.push(1);
    test.push(5);
    test.push(3);

    test.pull();

    test.printall();
}

void tmpmyqueuemainst()
{
    myTMPQueue<int> test(7);
    test.enqueue(1);
    test.enqueue(5);
    test.enqueue(3);

    myTMPNode<int> *cur = test.dequeue();
    cout << "test deq*** value = " << cur->getNum() << endl;
    delete cur;

    test.printall();
}

void tmpmydblistmain()
{
    myTMPDoubleLinkList<int> test(7);
    test.append(1);
    test.append(5);
    test.append(3);

    test.insert(1, 7);

    test.remove(2);

    test.printall();
}

void tmpmytreemain()
{
    myTMPTree<int> test;
    test.append(6);
    test.append(2);
    test.append(15);
    test.append(1);
    test.append(5);
    test.append(13);
    test.append(18);
    test.append(3);
    test.append(4);
    test.append(16);
    test.append(19);

    myTMPTreeNode<int> *node = nullptr;
    node = test.searchwidth(12);
    node = test.searchheight(3);
    node = test.searchsimm(18);

    test.remove(15);
}

int main()
{
    cout << "*mystructs program start*" << endl;

    //tmpmyqueuemainst();
    //tmpmylistmain();
    //tmpmydblistmain();
    tmpmytreemain();

    cout << "*mystructs program finish*" << endl;

    return 0;
}
