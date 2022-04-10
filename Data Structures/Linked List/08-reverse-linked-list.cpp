#include <bits/stdc++.h>
#include "00-linked-list.hpp"

using namespace std;

int main()
{
    LinkedList list = LinkedList();

    list.pushDefaultData();
    list.printList();
    list.reverse();
    list.printList();

    return 0;
}
