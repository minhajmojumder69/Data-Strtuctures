#include<bits/stdc++.h>
using namespace std;
class Node 
{
    public:
        int val;
        Node * next;

    Node(int val)  // With Costrctor;
    {
        this->val = val;
        this->next = NULL;
    }
};

int main()
{
    Node * head = new Node(10);
    Node * a = new Node(20);
    Node * b = new Node(30);

    head->next = a;
    a->next =b;

    
    Node * newnode = new Node(5);  // insert_at_head;
    newnode->next = head;
    head = newnode;

    
    Node * newnode3 = new Node(25); // insert at any position;
    Node * temp = head;
    for (int i = 0; i < 2; i++)   
    {
        temp = temp->next;
    }
    newnode3->next = temp->next;
    temp->next = newnode3;


    Node * newnode2 = new Node(35); // insert at tail;
    Node * tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newnode2;
    

    while (head != NULL)
    {
        cout  << head->val << endl;
        head = head->next;
    }
}