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
                 n1
                /  \
               n2   n3
              / \
             n4  n5
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

void PreOrder(BinaryTree *temp)
{
    if (temp == nullptr)
    {
        return;
    }

    cout << temp->data << " ";
    PreOrder(temp->left);
    PreOrder(temp->right);
}

void PostOrder(BinaryTree *temp)
{
    if (temp == nullptr)
    {
        return;
    }

    PostOrder(temp->left);
    PostOrder(temp->right);
    cout << temp->data << " ";
}

BinaryTree *NewNodeCreation(int val)
{
    NewNode= new BinaryTree();
    NewNode->data=val;
    NewNode->left=nullptr;
    NewNode->right=nullptr;
    return NewNode;
}

int main()
{
    root=NewNodeCreation(5);
    root->left=NewNodeCreation(6);
    root->right=NewNodeCreation(7);
    root->left->left=NewNodeCreation(8);
    root->left->right=NewNodeCreation(9);

    cout << "Preorder :- ";
    PreOrder(root);
    cout << endl;

    cout << "Inorder :- ";
    InOrder(root);
    cout << endl;

    cout << "Postorder :- ";
    PostOrder(root);
    cout << endl;

    return 0;
}