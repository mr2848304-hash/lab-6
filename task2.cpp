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

    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void deleteByValue(int value);
    void display();
};


LinkedList::LinkedList()
{
    head = NULL;
}


void LinkedList::insertAtBeginning(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}


void LinkedList::insertAtEnd(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void LinkedList::deleteByValue(int value)
{
    if (head == NULL)
        return;

    if (head->data == value)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->data != value)
    {
        temp = temp->next;
    }

    if (temp->next != NULL)
    {
        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
    }
}


void LinkedList::display()
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

    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtBeginning(5);

    list.display();

    list.deleteByValue(20);

    cout << "After deletion:\n";
    list.display();

    return 0;
}
