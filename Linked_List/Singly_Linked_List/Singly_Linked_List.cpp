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
public:
    Node *head;

    LinkedList()
    {
        this->head = nullptr;
    }

    ~LinkedList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *newnext = temp->next;
            delete temp;
            temp = newnext;
        }
    }

    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            this->head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
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
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            cout << "List is Empty !\n";
            return;
        }

        else if (head->data == num)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *temp = head;

        while ((temp != nullptr) && (temp->next != nullptr))
        {
            if (temp->next->data == num)
            {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }

        cout << "The Node with Value " << num << " was not found !\n\n";
        return;
    }

    void insertAfter(int data, int num)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            cout << "List is Empty !\n";
            return;
        }

        Node *temp = head;

        while (temp != nullptr)
        {
            if (temp->data == num)
            {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }

        cout << "The Node with value " << num << " could not be found !\n\n";
        return;
    }

    void removeFromStart()
    {
        if (head == nullptr)
        {
            cout << "List is Empty !\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void removeFromEnd()
    {
        if (head == nullptr)
        {
            cout << "List is Empty !\n";
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            return;
        }

        Node *temp = head;
        Node* prev;
        while (temp -> next != nullptr)
        {
            prev = temp;
            temp = temp->next;
        }
        delete temp;
        prev -> next = nullptr;
    }

    void removeBefore(int num)
    {
        if (head == nullptr)
        {
            cout << "List is Empty !\n";
            return;
        }
        if (head->data == num)
        {
            cout << "No Element Present Before " << num << endl;
            cout << num << " is First in the List !\n";
        }
        Node *temp = head;
        Node *prev;
        while (temp != nullptr && temp->next != nullptr)
        {
            if (temp->next->data == num)
            {
                prev->next = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        cout << "Could not Find The Node with data : " << num << endl;
        return;
    }

    void removeAfter(int num)
    {
        if (head == nullptr)
        {
            cout << "List is Empty !\n";
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == num)
            {
                if (temp->next == nullptr)
                {
                    cout << "No Node is Present After " << num << endl;
                    return;
                }
                Node *nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
                return;
            }
            temp = temp->next;
        }

        cout << "No Node with value " << num << "Found !\n";
        return;
    }

    void print()
    {
        if (head == nullptr)
        {
            cout << "The List us Empty !\n";
            return;
        }

        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n\n";
    }
};

int main()
{
    LinkedList List;
    List.insertAtEnd(10);
    List.insertAtEnd(20);
    List.insertAtEnd(30);
    List.insertAtEnd(40);
    List.insertAtEnd(50);
    List.insertAtEnd(60);
    List.print();
    List.insertAtStart(5);
    List.print();
    List.insertAfter(15, 10);
    List.print();
    List.insertBefore(25, 30);
    List.print();


    List.removeFromStart();
    List.print();
    List.removeFromEnd();
    List.print();
    // List.removeBefore(30);
    // List.print();
    // List.removeAfter(30);
    // List.print();
}
