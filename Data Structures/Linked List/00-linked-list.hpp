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
    
    void push(int data);

    void pushDefaultData();

    void printList();

    void deleteNode(int key);

    void deleteNode(Node*& node, int key);

    // deletes node at specified position
    void deleteNodeAt(int position);

    // length of linked list
    // iterative method
    int length();

    // length of list
    // recursive method
    int length(Node* node);
};
