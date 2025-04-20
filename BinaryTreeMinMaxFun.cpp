#include <iostream>
using namespace std;
struct BinaryTree
{
    int data;
    BinaryTree *left;
    BinaryTree *right;
};

int i;

BinaryTree *NewNode, *root, *temp;

/*

    {
                 5
                / \
               6   7
              / \
             8   9
    }

*/

void LargestNum(BinaryTree *temp)
{
    if (temp == nullptr)
        return;
    LargestNum(temp->left);
    if (i < temp->data)
        i = temp->data;
    LargestNum(temp->right);
}
void SmallestNum(BinaryTree *temp)
{
    if (temp == nullptr)
        return;
    SmallestNum(temp->left);
    if (i > temp->data)
        i = temp->data;
    SmallestNum(temp->right);
}
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

int main()
{
    root = NewNodeCreation(5);
    root->left = NewNodeCreation(6);
    root->right = NewNodeCreation(7);
    root->left->left = NewNodeCreation(8);
    root->left->right = NewNodeCreation(9);

    cout << "Inorder :- ";
    InOrder(root);
    cout << endl;
    i = root->data;
    LargestNum(root);
    cout << "Largest number = " << i << endl;
    SmallestNum(root);
    cout << "Smallest number = " << i << endl;

    return 0;
}