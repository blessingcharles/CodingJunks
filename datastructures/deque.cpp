#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Deque
{
public:
    int N;
    int count = 0;
    Node *head, *tail;
    Deque(int n)
    {
        N = n;
        tail = NULL;
        head = NULL;
    }
    bool pushFront(int x)
    {
        if (isFull())
            return false;
        Node *newnode = new Node(x);
        if (isEmpty())
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        count++;
        return true;
    }
    bool pushRear(int x)
    {
        if (isFull())
            return false;
        Node *newnode = new Node(x);
        if (isEmpty())
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            newnode->prev = tail;
            tail->next = newnode;
            tail = newnode;
        }
        count++;
        return true;
    }
    int popFront()
    {
        if (isEmpty())
            return -1;
        Node *temp = head;
        head = head->next;
        int val = temp->data;
        if (head == NULL)
        {
            tail = NULL;
        }
        count--;
        delete temp;
        return val;
    }
    int popRear()
    {
        if (isEmpty())
            return -1;
        Node *temp = tail;
        tail = tail->prev;
        int val = temp->data;
        if (tail == NULL)
        {
            head = NULL;
        }
        count--;
        delete temp;
        return val;
    }
    int getFront()
    {
        if (isEmpty())
            return -1;
        return head->data;
    }
    int getRear()
    {
        if (isEmpty())
            return -1;
        return tail->data;
    }
    bool isEmpty()
    {
        return (head == NULL);
    }
    bool isFull()
    {
        return (count == N);
    }
};

int main()
{

    return 0;
}