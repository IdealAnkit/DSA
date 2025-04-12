#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *tail, *temp, *pre, *toDelete;

void InsertAtBeg(int val)
{
    temp = (struct node *)malloc(sizeof(struct node));
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
    printf("Enter Position : ");
    scanf("%d", &p);
    temp = (struct node *)malloc(sizeof(struct node));
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
    temp = (struct node *)malloc(sizeof(struct node));
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
        printf("Enter position:-\n1. Starting\n2. Specific\n3. Ending\nChoose: ");
        scanf("%d", &n);
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
        printf("Invalid Choice\n");
        break;
    }
}

void DelAtBeg()
{
    toDelete = head;
    head = head->next;
    free(toDelete);
    printf("Node deleted successfully.\n");
}

void DelAtSpecific()
{
    int p;
    printf("Enter Position : ");
    scanf("%d", &p);

    pre = head;
    for (int i = 1; i < p; i++)
    {
        if (pre->next == NULL)
            break;

        pre = pre->next;
    }
    toDelete = pre->next;
    pre->next = toDelete->next;
    free(toDelete);
    printf("Node deleted successfully.\n");
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
            free(toDelete);
            printf("Node deleted successfully.\n");
            return;
        }

        toDelete = toDelete->next;
    }

    tail = toDelete;
    toDelete = toDelete->next;
    tail->next = NULL;
    free(toDelete);
    printf("Node deleted successfully.\n");
}

void Del()
{
    int n;
    if (head == NULL)
    {
        printf("List is already empty.\n");
        return;
    }
    else
    {
        printf("Enter position:-\n1. Starting\n2. Specific\n3. Ending\nChoose: ");
        scanf("%d", &n);
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
        printf("Invalid Choice\n");
        break;
    }
}

void reverse()
{
    struct node *prev = NULL, *curr = head, *NextNode = NULL;
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
        printf("Empty list.\n");
    }
    else
    {
        printf("List elements :- ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    head = NULL;
    tail = NULL;
    int op = 0;
    int val;
    while (op != 5)
    {
        printf("Choose:-\n1. Append\n2. Delete\n3. Display\n4. Reverse\n5. Exit\nEnter choice: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &val);
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
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}
