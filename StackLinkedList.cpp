#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *top, *temp;
void push(int val)
{
    temp = new node();

    if (top == NULL)
    {
        temp->data = val;
        temp->next = NULL;
        top = temp;
    }
    else
    {
        temp->data = val;
        temp->next = top;
        top = temp;
    }
}
void pop()
{
    if (top == NULL)
    {
        cout << "Stack is Underflow." << endl;
    }
    else
    {
        temp = top;
        top = top->next;
        temp->next = NULL;
        cout << temp->data << " is deleted." << endl;
        free(temp);
    }
}
void display()
{
    temp = top;
    if (top == NULL)
    {
        cout << "Empty Stack." << endl;
    }
    else
    {
        cout << "Stack elements :- ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
void reverse()
{
    node *prev = NULL, *curr = top, *NextNode = NULL;
    while (curr != NULL)
    {
        NextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = NextNode;
    }
    top = prev;
}
int main()
{
    top = NULL;
    int op = 0, val;
    while (op != 5)
    {
        cout << "Choose:\n1. Push\n2. Pop\n3. Display\n4. Reverse\n5. Exit\nEnter choice: ";
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Enter Data: ";
            cin >> val;
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            reverse();
            cout << "Stack Reversed." << endl;
            break;
        case 5:
            op = 5;
            break;
        default:
            cout << "Invalid Choice.";
            break;
        }
    }
    return 0;
}