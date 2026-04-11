#include<iostream>
using namespace std;

class Node
{
public:
    string name;
    int priority;
    Node* next;
};

class BookQueue
{
    Node* head;

public:
    BookQueue();

    void addStudent(string name, int priority);
    void removeStudent(string name);
    void updatePriority(string name, int newPriority);
    void serveStudent();
    void display();
    void count();
};

BookQueue::BookQueue()
{
    head = NULL;
}


void BookQueue::addStudent(string name, int priority)
{
    Node* newNode = new Node;
    newNode->name = name;
    newNode->priority = priority;
    newNode->next = NULL;

    if (head == NULL || priority > head->priority)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->priority >= priority)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}


void BookQueue::removeStudent(string name)
{
    if (head == NULL) return;

    if (head->name == name)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->name != name)
        temp = temp->next;

    if (temp->next != NULL)
    {
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
}


void BookQueue::updatePriority(string name, int newPriority)
{
    removeStudent(name);
    addStudent(name, newPriority);
}


void BookQueue::serveStudent()
{
    if (head == NULL) return;

    Node* temp = head;
    cout << "Served: " << temp->name << endl;
    head = head->next;
    delete temp;
}


void BookQueue::display()
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->name << "(" << temp->priority << ") -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


void BookQueue::count()
{
    int c = 0;
    Node* temp = head;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    cout << "Students: " << c << endl;
}

int main()
{
    BookQueue book1, book2;

    book1.addStudent("Ali", 2);
    book1.addStudent("Sara", 5);
    book1.addStudent("Ahmed", 3);

    book1.display();

    book1.updatePriority("Ali", 6);
    book1.display();

    book1.serveStudent();
    book1.display();

    book1.count();

    return 0;
}