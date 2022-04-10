#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node() { }

    Node(int data)
    {
        this->data = data;
    }
};

class LinkedList
{
    public:
    Node* head;

    void push(int data)
    {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    // delete node using iterative method
    void deleteNode(int key)
    {
        Node* temp = head;
        Node* prev = NULL;

        // head node contains the node to be deleted
        if (temp != NULL && temp->data == key)
        {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Key not found!\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        return;
    }

    // delete node using recursive call
    void deleteNode(Node*& node, int key)
    {
        // check if list is empty or end of list
        if (node == NULL)
        {
            cout << "Key not found!\n";
            return;
        }

        // if current node is the node to be deleted
        if (node->data == key)
        {
            Node* temp = node;
            node = node->next;
            delete temp;
            return;
        }

        deleteNode(node->next, key);
    }

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
    for (int i = 10; i <= 50; i+= 10)
    {
        list.push(i);
    }

    // list.printList();
    // list.deleteNode(30);
    list.printList();

    list.deleteNode(list.head, 20);
    list.printList();

    return 0;
}
