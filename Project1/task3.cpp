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

    void insertAtPosition(int value, int pos);
    void deleteAtPosition(int pos);
    void search(int value);
    void countNodes();
    void display();
};


LinkedList::LinkedList()
{
    head = NULL;
}


void LinkedList::insertAtPosition(int value, int pos)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Invalid position\n";
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


void LinkedList::deleteAtPosition(int pos)
{
    if (head == NULL) return;

    if (pos == 1)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL) return;

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}


void LinkedList::search(int value)
{
    Node* temp = head;
    int pos = 1;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            cout << "Found at position: " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }

    cout << "Not found\n";
}


void LinkedList::countNodes()
{
    Node* temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    cout << "Total nodes: " << count << endl;
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
    int choice, val, pos;

    while (true)
    {
        cout << "\n1.Insert\n2.Delete\n3.Search\n4.Count\n5.Display\n6.Exit\n";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter value and position: ";
            cin >> val >> pos;
            list.insertAtPosition(val, pos);
        }
        else if (choice == 2)
        {
            cout << "Enter position: ";
            cin >> pos;
            list.deleteAtPosition(pos);
        }
        else if (choice == 3)
        {
            cout << "Enter value: ";
            cin >> val;
            list.search(val);
        }
        else if (choice == 4)
        {
            list.countNodes();
        }
        else if (choice == 5)
        {
            list.display();
        }
        else break;
    }

    return 0;
}