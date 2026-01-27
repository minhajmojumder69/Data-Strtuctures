#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node* newnode = new Node(val); // creating newnode;

    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    
    tail->next = newnode;  // connecting newnode;
    tail = newnode; 
}

void printing_liked_list(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << endl;
        head = head->next;
    }
}

int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *tail = new Node(30);

    head->next = a;
    a->next = tail;

    insert_at_tail(head,tail, 69);
    insert_at_tail(head,tail, 696);
    printing_liked_list(head);

    return 0;
} 