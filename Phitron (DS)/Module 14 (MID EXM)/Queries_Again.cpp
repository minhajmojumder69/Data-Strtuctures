#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_any_position(Node *&head, Node *&tail, int idx, int val)
{
    Node *newnode = new Node(val);

    if (idx == 0)
    {
        if (head == NULL)
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
        return;
    }

    Node *tmp = head;
    for (int i = 0; i < idx - 1; i++)
    {
        tmp = tmp->next;
    }
    newnode->next = tmp->next;
    newnode->prev = tmp;

    if (tmp->next != NULL)
    {
        tmp->next->prev = newnode;
    }
    else
    {
        tail = newnode; 
    }
    tmp->next = newnode;
}

void print_forward(Node *head)
{
    cout << "L -> ";
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void print_backward(Node * tail)
{
    cout << "R -> ";
    Node* tmp = tail;
    while (tmp != NULL)
    {
        cout << tmp->val << " " ;
        tmp = tmp->prev;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int idx, val;
        cin >> idx >> val;

        if (idx < 0 || idx > sz)
            cout << "Invalid" << endl;
        else
        {
            insert_at_any_position(head, tail, idx, val);
            sz++;
            print_forward(head);
            print_backward(tail);
        }
    }

    return 0;
}
