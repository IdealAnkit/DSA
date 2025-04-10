#include <iostream>
using namespace std;
#define size 5
int front = -1;
int back = -1;
int queue[size];

void dequeue()
{
    if (front == -1 && back == -1)
    {
        cout << "Queue is empty." << endl;
    }
    else if (front == back)
    {
        cout << queue[front] << " is deleted. " << endl;
        front = -1;
        back = -1;
    }
    else
    {
        cout << queue[front] << " is deleted. " << endl;
        front = (front + 1) % size;
    }
}

void enqueue(int data)
{
    if ((back + 1) % size == front)
    {
        cout << "Queue is full." << endl;
    }
    else if (front == -1 && back == -1)
    {
        front = 0;
        back = 0;
        queue[back] = data;
    }
    else
    {
        back = (back + 1) % size;
        queue[back] = data;
    }
}

void printqueue()
{
    cout << "Your Queue is : " << endl;
    if (front == -1 && back == -1)
    {
        cout << "Empty";
    }
    else
    {
        int i = front;
        do
        {
            cout << queue[i] << " ";
            i = (i + 1) % size;
        } while (i != (back + 1) % size);
    }
    cout << endl;
}


int main()
{
    int op = 0;
    int choose;
    while (op != 4)
    {
        cout << "Choose :- \n1 -> Enqueue  \n2 -> Dequeue  \n3 -> Print Queue \n4 -> Exit" << endl;
        cout << "Enter your choice : ";
        cin >> op;
        int i = front;

        switch (op)
        {
        case 1:
            int val;
            cout << "Enter the element : ";
            cin >> val;
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printqueue();
            break;
        case 4:
            op=4;
            break;
        default:
            cout<<"Invalid Choice"<<endl;
            break;
        }
    }
    return 0;
}