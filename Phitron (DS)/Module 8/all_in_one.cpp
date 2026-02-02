#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int val;
        Node* next;
        Node* prev;
        
        Node(int val)
        {
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }

};

void insert_at_head(Node * &head,int val)
{
    Node* newnode = new Node(val);
   
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
 
}

void delete_head(Node *&head, Node *&tail)
{
    Node *delete_node = head;
    head = head->next;
    delete delete_node;
    if (head == NULL)
    {
        tail = NULL;
        return;
    }
    head->prev = NULL;
}

void insert_at_any_position(Node * &head,int idx,int val)
{
    Node* newnode = new Node(val);
   
    Node* tmp = head;
    for (int i = 0; i < idx -1 ; i++)
    {
        tmp = tmp->next;
    }
    newnode->next = tmp->next;
    tmp->next = newnode;
    newnode->prev = tmp;
}

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

void insert_at_tail(Node * &tail,int val)
{
    Node* newnode = new Node(val);
   
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
 
}

void delete_tail(Node *&head, Node *&tail)
{
    Node *delete_node = tail;
    tail = tail->prev;
    delete delete_node;
    if (tail == NULL)
    {
        head = NULL;
        return;
    }
    tail->next = NULL;
}

void print_forward(Node * head)
{
    Node* tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " " ;
        tmp = tmp->next;
    }
    cout << endl;
}

void print_backward(Node * tail)
{
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
    Node * head = new Node(10);
    Node * a = new Node(20);
    Node * tail = new Node(30);

    head->next = a;
    a->prev = head;

    a->next = tail;
    tail->prev = a;

    insert_at_head(head,5);
    print_forward(head);

  return 0;
}
