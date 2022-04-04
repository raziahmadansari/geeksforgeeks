#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int value;
    Node* next;

    static void printList(Node* n)
    {
        while (n != NULL)
        {
            printf(" %d ", n->value);
            n = n->next;
        }
    }
};

int main()
{
    // Create 3 nodes
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // Allocate 3 nodes in the heap
    head = new Node();
    second = new Node();
    third = new Node();

    // Assign values and next pointer to nodes
    head->value = 1;    head->next = second;
    second->value = 2;  second->next = third;
    third->value = 3;   third->next = NULL;

    // Print linked list
    Node::printList(head);

    return 0;
}
