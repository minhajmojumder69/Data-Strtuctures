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
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void duplicate_remove(Node *head, Node* &tail)
{
    Node* tmp = head;
    for (Node *i = head; i != NULL; i = i->next)
    {
        for (Node *j = i; j->next != NULL; )
        {
            if (j->next->val == i->val)
            {
                Node *duplicete = j->next;
                j->next = j->next->next;

                if (j->next == NULL)
                {
                    tail = j;
                }
                delete duplicete;
            }
            else
            {
                j = j->next;
            }
            
            
        }
    }
    
}
void printing_linked_list(Node *head)
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
    Node *head = NULL;
    Node *tail = NULL;

    int val;
    while (1)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }

        insert_at_tail(head, tail, val);
    }
    duplicate_remove(head,tail);
    printing_linked_list(head);
    return 0;
}