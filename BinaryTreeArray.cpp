#include <iostream>
using namespace std;

struct BinaryTree
{
    int data;
    BinaryTree *left;
    BinaryTree *right;
};

BinaryTree *NewNode, *root, *temp;

/*

    {
                 n1               5
                /  \    
               n2   n3          4   6
              / \
             n4  n5         1     0
    }

*/

void InOrder(BinaryTree *temp)
{
    if (temp == nullptr)
    {
        return;
    }

    InOrder(temp->left);
    cout << temp->data << " ";
    InOrder(temp->right);
}





BinaryTree *NewNodeCreation(int val)
{
    NewNode = new BinaryTree();
    NewNode->data = val;
    NewNode->left = nullptr;
    NewNode->right = nullptr;
    return NewNode;
}

void Insert(BinaryTree *temp)
{
    if (temp == nullptr)
    {
        return;
    }

    if (temp->data > NewNode->data)
    {
        if (temp->left != nullptr)
        {
            Insert(temp->left);
            return;
        }
        else
        {
            temp->left = NewNode;
            return;
        }
    }

    if (temp->data < NewNode->data)
    {
        if (temp->right != nullptr)
        {
            Insert(temp->right);
            return;
        }
        else
        {
            temp->right = NewNode;
            return;
        }
    }
}

int main()
{
    int i = 1, val;
    root = NewNodeCreation(10);
    root->left = NewNodeCreation(4);
    root->right = NewNodeCreation(12);
    root->left->left = NewNodeCreation(2);
    root->left->right = NewNodeCreation(5);

    int a[]={3,5,7,8,0,9,78};
    for (int i = 0; i < 7; i++)
    {
        NewNode = NewNodeCreation(a[i]);
        Insert(root);
    }
    

    cout << "Inorder :- ";
    InOrder(root);
    cout << endl;

    while (i != 0)
    {
        cout << "Enter Choice :\n0. End\n1. Insert\n2. Print Inorder\nEnter : ";
        cin >> i;
        switch (i)
        {
        case 1:
        {
            cout << "Enter data : ";
            cin >> val;
            NewNode = NewNodeCreation(val);
            Insert(root);
            break;
        }
        case 2:
        {
            cout << "Inorder :- ";
            InOrder(root);
            cout << endl;
            break;
        }
        case 0:
        {
            break;
        }
        default:
        cout<<"Invadlid.";
            break;
        }
    }

    return 0;
}