#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class LinkedList
{
    Node* head;

public:
    LinkedList();

    void CreateNode(int value);
    void Display();
};


LinkedList::LinkedList()
{
    head = NULL;
}


void LinkedList::CreateNode(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void LinkedList::Display()
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main()
{
    LinkedList list;

    list.CreateNode(10);
    list.CreateNode(20);
    list.CreateNode(30);

    list.Display();

    return 0;
}
