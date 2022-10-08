#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

Node *top = NULL;

void Push(int val)
{
    Node *element = new Node(val);

    if (top == NULL)
    {
        top = element;
    }
    else
    {
        element->next = top;
        top = element;
    }
    cout << "Node pushed successfully!" << endl;
}
bool is_underflow()
{
    if (top == NULL)
        return true;
    else
        return false;
}
void pop()
{
    Node *temp = NULL;
    if (is_underflow())
    {
        cout << "Stack Underflows!" << endl;
    }
    else
    {
        temp = top;
        top = top->next;
        cout << "The popped element is " << temp->data << endl;
    }
}
int peek()
{
    if (!is_underflow())
    {
        return top->data;
    }
    else
    {
        return 0;
    }
}
void display()
{
    Node *temp = top;
    cout << "The stack is" << endl;
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
        cout << endl;
    }
}
int main()
{
    int ch, val;
    do
    {
        cout << "1) Push in stack" << endl;
        cout << "2) Pop from stack" << endl;
        cout << "3) Peek the stack" << endl;
        cout << "4) Display stack" << endl;
        cout << "5) Exit" << endl;
        cout << "- - - - - - - - -  -" << endl;
        cout << "Enter your choice..." << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter value to be pushed:" << endl;
            cin >> val;
            Push(val);
            break;
        }

        case 2:
        {
            pop();
            break;
        }

        case 3:
        {
            int t = peek();
            cout << t << endl;
            break;
        }
        case 4:
        {
            display();
            break;
        }
        case 5:
        {
            exit(0);
            break;
        }
        default:
        {
            cout << "Wrong Choice";
        }
        }
    } while (ch < 6);
    return 0;
}