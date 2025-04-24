#include <iostream>
using namespace std;
int arr[5],i=-1;
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

void ArrCreation(BinaryTree *temp)
{
    if (temp == nullptr)
    {
        return;
    }

    ArrCreation(temp->left);
    arr[++i]=temp->data;
    ArrCreation(temp->right);
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

int main()
{
    BinaryTree *n1, *n2, *n3, *n4, *n5;
    n1 = new BinaryTree();
    n1->data = 5;
    n1->left = nullptr;
    n1->right = nullptr;
    root = n1;

    n2 = new BinaryTree();
    n2->data = 6;
    n2->left = nullptr;
    n2->right = nullptr;

    n3 = new BinaryTree();
    n3->data = 7;
    n3->left = nullptr;
    n3->right = nullptr;

    n4 = new BinaryTree();
    n4->data = 8;
    n4->left = nullptr;
    n4->right = nullptr;

    n5 = new BinaryTree();
    n5->data = 9;
    n5->left = nullptr;
    n5->right = nullptr;

    n1->left = n2;
    n1->right = n3;

    n2->left = n4;
    n2->right = n5;

    cout << "Inorder :- ";
    InOrder(root);
    cout << endl;

    ArrCreation(root);
    cout << endl;

    int min=arr[0];
    for (int j = 0; j < 5; j++)
    {
        if (arr[j]<min)
        {
            min=arr[j];
        }
        
    }
    cout << "Minimum value = "<<min<<endl;
    
    int max=arr[0];
    for (int j = 0; j < 5; j++)
    {
        if (arr[j]>max)
        {
            max=arr[j];
        }
        
    }
    cout << "Maximum value = "<<max<<endl;
    

    return 0;
}