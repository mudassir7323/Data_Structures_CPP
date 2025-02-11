#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data = 0)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    ~LinkedList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
    }

    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (!head)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtStart(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertBefore(int data, int num)
    {
        if (!head)
        {
            cout << "List is empty!\n";
            return;
        }

        Node *newNode = new Node(data);
        if (head->data == num)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next && temp->next->data != num)
        {
            temp = temp->next;
        }

        if (!temp->next)
        {
            cout << "Node with value " << num << " not found!\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAfter(int data, int num)
    {
        Node *temp = head;
        while (temp && temp->data != num)
        {
            temp = temp->next;
        }

        if (!temp)
        {
            cout << "Node with value " << num << " not found!\n";
            return;
        }

        Node *newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void print() const
    {
        if (!head)
        {
            cout << "The list is empty!\n";
            return;
        }

        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main()
{
    LinkedList List;
    List.insertAtEnd(10);
    List.insertAtEnd(20);
    List.insertAtEnd(30);
    List.insertAtEnd(40);
    List.print();
    List.insertAtStart(5);
    List.print();
    List.insertAfter(15, 10);
    List.print();
    List.insertBefore(25, 30);
    List.print();
}
