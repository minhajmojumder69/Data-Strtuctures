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
void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}
void delete_at_any_pos(Node *&head, Node *&tail, int n)
{
    int idx = 0;
    Node *tmp_idx = head;
    while (tmp_idx != NULL)
    {
        idx++;
        tmp_idx = tmp_idx->next;
    }
    if (n >= idx || n < 0)
    {
        return;
    }

    if (n == 0)
    {
        Node *deletenode = head;
        head = head->next;
        delete deletenode;
        if (head == NULL)
        {
            tail = NULL;
        }
        return;
    }
    Node *tmp = head;
    for (int i = 0; i < n - 1; i++)
    {
        tmp = tmp->next;
    }

    Node *deletenode = tmp->next;
    tmp->next = tmp->next->next;
    if (tmp->next == NULL)
    {
        tail = tmp;
    }
    delete deletenode;
}
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

    int Q;
    cin >> Q;
    for(int i = 1;i <= Q; i++)
    {
        int x, v;
        cin >> x >> v;
        if (x == 0)
        {
            insert_at_head(head, tail, v);
        }
        else if (x == 1)
        {
            insert_at_tail(head, tail, v);
        }
        else if (x == 2)
        {
            delete_at_any_pos(head, tail, v);
        }
        printing_linked_list(head);
        cout << endl;
    }

    return 0;
}