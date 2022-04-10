#include <iostream>
#include "00-linked-list.hpp"

void LinkedList::push(int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void LinkedList::pushDefaultData()
{
    if (head != NULL)
    {
        std::cout << "List already initialized!\n";
        return;
    }

    for (int i = 10; i >= 1; i--)
    {
        LinkedList::push(i * 10);
    }
}

void LinkedList::printList()
{
    Node* node = head;
    while (node != NULL)
    {
        std::cout << node->data;
        node = node->next;
        if (node != NULL)
        {
            std::cout << " -> ";
        }
    }
    std::cout << "\n";
}

void LinkedList::deleteNode(int key)
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
        std::cout << "Key not found!\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    return;
}

void LinkedList::deleteNode(Node*& node, int key)
{
    // check if list is empty or end of list
    if (node == NULL)
    {
        std::cout << "key not found!\n";
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

void LinkedList::deleteNodeAt(int position)
{
    if (head == NULL)
    {
        std::cout << "List is empty!\n";
        return;
    }

    // store head node
    Node* temp = head;

    // if head needs to be removed
    if (position == 0)
    {
        head = head->next;
        free(temp);
        return;
    }

    // find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }

    // if position is more than the number of nodes
    if (temp == NULL || temp->next == NULL)
    {
        std::cout << "Index out of bound!\n";
        return;
    }

    Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
    return;
}

int LinkedList::length()
{
    int count = 0;
    Node* node = head;
    while (node != NULL)
    {
        count++;
        node = node->next;
    }

    return count;
}

int LinkedList::length(Node* node)
{
    if (node == NULL)
    {
        return 0;
    }

    return 1 + length(node->next);
}

void LinkedList::addXtoList(int num)
{
    if (head == NULL)
    {
        std::cout << "List is empty!\n";
    }

    Node* node = head;
    while (node != NULL)
    {
        node->data += num;
        node = node->next;
    }
}

void LinkedList::swap(int x, int y)
{
    // nothing to do if x and y are equal
    if (x == y)
        return;

    Node* prevX = NULL;
    Node* currX = head;
    while (currX != NULL && currX->data != x)
    {
        prevX = currX;
        currX = currX->next;
    }

    Node* prevY = NULL;
    Node* currY = head;
    while (currY != NULL && currY->data != y)
    {
        prevY = currY;
        currY = currY->next;
    }

    // if either of x or y not present,
    // nothing to do
    if (currX == NULL || currY == NULL)
        return;

    // if x is not head of linked list
    if (prevX != NULL)
    {
        prevX->next = currY;
    }
    else // make y as new head
    {
        head = currY;
    }

    // if y is not head of linked list
    if (prevY != NULL)
    {
        prevY->next = currX;
    }
    else // make x as new head
    {
        head = currX;
    }

    // swap next pointers
    Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

void LinkedList::reverse()
{
    // check if list is empty
    if (head == NULL)
        return;
    
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}
