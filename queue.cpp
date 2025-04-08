#include <iostream>
using namespace std;
#define size 5
int front = -1;
int back = -1;
int queue[size];

void dequeue()
{
    if (front == -1 and back == -1)
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
        front++;
    }
}

void enqueue(int data)
{
    if (back == size - 1)
    {
        cout << "Queue is full." << endl;
    }
    else if (front == -1 and back == -1)
    {
        front = 0;
        back = 0;
        queue[back] = data;
    }
    else
    {
        back++;
        queue[back] = data;
    }
}

int main()
{
    int p = 0; // terminating condition
    int choose;
    while (p != 1)
    {
        cout << "Choose : \n1 -> Enqueue  \n2 -> Dequeue  \n3 -> Print Queue \n4 -> Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choose;
        int i = front;

        if (choose == 1)
        {
            int val;
            cout << "Enter the element : ";
            cin >> val;
            enqueue(val);
        }
        else if (choose == 2)
        {
            dequeue();
        }
        else if (choose == 3)
        {
            cout << "Your Queue is : " << endl;
            if (front == -1 and back == -1)
            {
                cout << "Empty";
            }
            else
            {
                for (i; i <= back; i++)
                {
                    cout << queue[i] << " ";
                }
            }

            cout << endl;
        }
        else if (choose == 4)
        {
            p = 1;
        }
        else
        {
            cout << "Invalid Choice..." << endl;
        }
    }
    return 0;
}