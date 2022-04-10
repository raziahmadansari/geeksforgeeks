#include <bits/stdc++.h>
#include "00-linked-list.hpp"

using namespace std;

int main()
{
    LinkedList list = LinkedList();

    list.pushDefaultData();
    list.printList();
    cout << "Length = " << list.length() << endl;

    cout << "Length = " << list.length(list.head) << endl;

    return 0;
}
