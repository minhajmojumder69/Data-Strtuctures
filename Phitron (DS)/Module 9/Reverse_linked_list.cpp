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

void reverse_linked_list(Node *&head,Node*&tail ,Node* tmp)
{
    if (tmp->next == NULL)
    {
        head = tmp;
        return;
    }
    reverse_linked_list(head,tail,tmp->next);
    tmp->next->next = tmp;
    tmp->next = NULL;
    tail = tmp;
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
    reverse_linked_list(head,tail,head);
    printing_liked_list(head);
    return 0;
}