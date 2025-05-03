#include <iostream>
#include <cstdlib>

using namespace std;

struct node
{
    int data;
    node *next;
};

node *head, *tail, *temp, *pre, *toDelete;

void InsertAtBeg(int val)
{
    temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

void InsertAtSpecific(int val)
{
    int p;
    cout << "Enter Position : ";
    cin >> p;
    temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }

    pre = head;
    for (int i = 1; i < p; i++)
    {
        if (pre->next == NULL)
            break;

        pre = pre->next;
    }
    temp->next = pre->next;
    pre->next = temp;
}

void InsertAtEnd(int val)
{
    temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void append(int val)
{
    int n;
    if (head == NULL)
    {
        n = 3;
    }
    else
    {
        cout << "Enter position:-\n1. Starting\n2. Specific\n3. Ending\nChoose: ";
        cin >> n;
    }
    switch (n)
    {
    case 1:
        InsertAtBeg(val);
        break;
    case 2:
        InsertAtSpecific(val);
        break;
    case 3:
        InsertAtEnd(val);
        break;
    default:
        cout << "Invalid Choice" << endl;
        break;
    }
}

void DelAtBeg()
{
    toDelete = head;
    head = head->next;
    delete toDelete;
    cout << "Node deleted successfully." << endl;
}

void DelAtSpecific()
{
    int p;
    cout << "Enter Position : ";
    cin >> p;

    pre = head;
    for (int i = 1; i < p; i++)
    {
        if (pre->next == NULL)
            break;

        pre = pre->next;
    }
    toDelete = pre->next;
    pre->next = toDelete->next;
    delete toDelete;
    cout << "Node deleted successfully." << endl;
}

void DelAtEnd()
{

    toDelete = head;
    for (int i = 1; toDelete->next != tail; i++)
    {
        if (toDelete->next == NULL)
        {
            head = NULL;
            tail = NULL;
            delete toDelete;
            cout << "Node deleted successfully." << endl;
            return;
        }

        toDelete = toDelete->next;
    }

    tail = toDelete;
    toDelete = toDelete->next;
    tail->next = NULL;
    delete toDelete;
    cout << "Node deleted successfully." << endl;
}

void Del()
{
    int n;
    if (head == NULL)
    {
        cout << "List is already empty." << endl;
        return;
    }
    else
    {
        cout << "Enter position:-\n1. Starting\n2. Specific\n3. Ending\nChoose: ";
        cin >> n;
    }
    switch (n)
    {
    case 1:
        DelAtBeg();
        break;
    case 2:
        DelAtSpecific();
        break;
    case 3:
        DelAtEnd();
        break;
    default:
        cout << "Invalid Choice" << endl;
        break;
    }
}

void reverse()
{
    node *prev = NULL, *curr = head, *NextNode = NULL;
    tail = head;
    while (curr != NULL)
    {
        NextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = NextNode;
    }
    head = prev;
}

void display()
{
    temp = head;
    if (head == NULL)
    {
        cout << "Empty list." << endl;
    }
    else
    {
        cout << "List elements :- ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    head = NULL;
    tail = NULL;
    int op = 0;
    while (op != 5)
    {
        cout << "Choose:-\n1. Append\n2. Delete\n3. Display\n4. Reverse\n5. Exit\nEnter choice: ";
        cin >> op;
        switch (op)
        {
        case 1:
            int val;
            cout << "Enter data : ";
            cin >> val;
            append(val);
            break;
        case 2:
            Del();
            break;
        case 3:
            display();
            break;
        case 4:
            reverse();
            break;
        case 5:
            op = 5;
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }
    return 0;
}