#include<iostream>
using namespace std;

class Node
{
public:
    string name;
    Node* next;
};

class HospitalQueue
{
    Node* head;

public:
    HospitalQueue();

    void addPatient(string name);
    void removePatient(string name);
    void display();
    void count();
};

HospitalQueue::HospitalQueue()
{
    head = NULL;
}

void HospitalQueue::addPatient(string name)
{
    Node* newNode = new Node;
    newNode->name = name;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void HospitalQueue::removePatient(string name)
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

void HospitalQueue::display()
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->name << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void HospitalQueue::count()
{
    int c = 0;
    Node* temp = head;

    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }

    cout << "Patients: " << c << endl;
}

int main()
{
    HospitalQueue h;

    h.addPatient("Ali");
    h.addPatient("Ahmed");
    h.addPatient("Sara");

    h.display();

    h.removePatient("Ahmed");

    h.display();
    h.count();

    return 0;
}