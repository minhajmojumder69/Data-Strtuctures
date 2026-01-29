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

void delete_at_any_position(Node *&head,int idx)
{
    Node *tmp = head;
    for (int i = 1; i < idx ; i++)
    {
        tmp=tmp->next;
    }
    Node *delete_node = tmp->next;
    tmp->next = tmp->next->next;
    tmp->next->prev = tmp;
    delete delete_node;
    
}

void print_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}

int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *tail = new Node(30);

    head->next = a;
    a->prev = head;

    a->next = tail;
    tail->prev = a;

    delete_at_any_position(head,1);
    print_linked_list(head);

    return 0;
}