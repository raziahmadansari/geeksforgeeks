#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

class LinkedList
{
    public:
    Node* head;

    // At the front of linked list
    void push(int data)
    {
        Node* new_node = createNode(data);
        new_node->next = head;
        head = new_node;
    }

    // Insert after particular node
    void insertAfter(Node* prev_node, int data)
    {
        if (prev_node == NULL)
        {
            cout << "The given previous node cannot be null.\n";
            return;
        }

        Node* new_node = createNode(data);
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    }

    // Insert at the end of list
    void append(int data)
    {
        Node* node = head;
        while (node->next != NULL)
        {
            node = node->next;
        }

        Node* new_node = createNode(data);
        node->next = new_node;
    }

    Node* createNode(int data)
    {
        Node* new_node = new Node();
        new_node->data = data;
        return new_node;
    }

    // Print linked list
    void printList()
    {
        Node* node = head;
        while (node != NULL)
        {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list = LinkedList();
    for (int i = 10; i <= 50; i += 10)
    {
        list.push(i);
    }

    list.printList();

    // insert after 30
    list.insertAfter(list.head, 100);

    list.printList();

    list.append(200);
    list.append(210);
    list.append(220);

    list.printList();

    return 0;
}
