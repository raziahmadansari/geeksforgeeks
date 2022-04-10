#include <bits/stdc++.h>
#include "00-linked-list.hpp"

using namespace std;

int main()
{
    LinkedList list = LinkedList();
    list.push(10);
    list.push(20);
    list.push(30);

    list.printList();
    list.deleteNodeAt(10);
    list.deleteNodeAt(1);
    list.printList();

    return 0;
}
