#include <iostream>
#include <vector>
#include <list>
using namespace std;

//* create stack using LINKED LIST (Using Creating Own Node and List);

template <class T>
class Node
{
public:
    T data;
    Node *next;

    Node(T val)
    {
        data = val;
        next = NULL;
    }
};

template <class T>

class Stack
{

    Node<T> *head;

public:
    Stack()
    {
        head = NULL;
    }
    void push(T val)
    {
        // push_front
        Node<T> *newNode = new Node<T>(val);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void pop()
    {
        // pop_front
        Node<T> *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    T top()
    {
        return head->data;
    }
    bool isEmpty()
    {
        return head == NULL;
    }
};

int main()
{
    Stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    while (!s.isEmpty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}