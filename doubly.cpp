#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};
void insert_athead(Node *&head, Node *&tail, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insert_attail(Node *&head, Node *&tail, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void insert_atpos(Node *&head, Node *&tail, int pos, int d)
{
    if (pos == 1)
    {
        insert_athead(head, tail, d);
        return;
    }
    Node *temp = head;
    int cur = 1;
    while (cur < pos - 1)
    {
        temp = temp->next;
        cur++;
    }
    if (temp == NULL)
    {
        insert_attail(head, tail, d);
    }
    else
    {
        Node *toAdd = new Node(d);
        toAdd->next = temp->next;
        temp->next->prev = toAdd;
        temp->next = toAdd;
        toAdd->prev = temp;
    }
}

int calc_size(Node *&head)
{
    Node *temp = head;
    int s = 0;
    while (temp != NULL)
    {
        s++;
        temp = temp->next;
    }
    return s;
}

void del_node(Node *&head, int pos)
{

    if (pos == 1)
    {
        Node *todel = head;
        head = head->next;
        head->prev = NULL;
        todel->next = NULL;
        delete todel;
    }
    else
    {
        Node *cur = head;
        Node *prev = NULL;
        int c = 0;
        int size = calc_size(head);

        if (pos > size)
        {
            cout << "you crossed the limit" << endl;
            return;
        }
        while (c < pos - 1 && cur->next != NULL)
        {
            prev = cur;
            cur = cur->next;
            c++;
        }
        if (cur->next == NULL)
        {
            prev->next = NULL;
            cur->prev = NULL;
            cur->next = NULL;

            delete cur;
            return;
        }

        cur->prev = NULL;
        prev->next = cur->next;
        cur->next->prev = prev;
        cur->next = NULL;

        delete cur;
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "X" << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insert_attail(head, tail, 10);
    insert_attail(head, tail, 20);
    insert_attail(head, tail, 30);
    insert_attail(head, tail, 40);
    insert_attail(head, tail, 60);
    insert_atpos(head, tail, 2, 78);
    insert_attail(head, tail, 70);

    int size = calc_size(head);

    print(head);
    cout << size << endl;
    del_node(head, 1);
    print(head);
    del_node(head, 3);
    print(head);
    del_node(head, 3);
    print(head);
    insert_attail(head, tail, 80);
    print(head);
    cout << calc_size(head) << endl;
    del_node(head, 5);
    print(head);

    return 0;
}
