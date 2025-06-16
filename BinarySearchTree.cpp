#include <iostream>
using namespace std;

struct BinaryTree {
    int data;
    BinaryTree *left;
    BinaryTree *right;
};

BinaryTree* NewNodeCreation(int val) {
    BinaryTree* newNode = new BinaryTree();
    newNode->data = val;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void Insert(BinaryTree*& root, int val) {
    if (root == nullptr) {
        root = NewNodeCreation(val);
        return;
    }

    if (val < root->data) {
        if (root->left != nullptr) {
            Insert(root->left, val);
        } else {
            root->left = NewNodeCreation(val);
        }
    } else if (val > root->data) {
        if (root->right != nullptr) {
            Insert(root->right, val);
        } else {
            root->right = NewNodeCreation(val);
        }
    } else {
        cout << "Duplicate value: " << val << " ignored." << endl;
    }
}

void InOrder(BinaryTree* root) {
    if (root == nullptr) {
        return;
    }

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

int main() {
    BinaryTree* root = nullptr;

    int initialValues[] = {10, 4, 12, 2, 5, 3, 7, 8, 0, 9, 78};
    for (int val : initialValues) {
        Insert(root, val);
    }

    cout << "Inorder traversal: ";
    InOrder(root);
    cout << endl;

    int choice = 1, val;
    while (choice != 0) {
        cout << "Enter Choice :\n0. End\n1. Insert\n2. Print Inorder\nEnter : ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter data : ";
                cin >> val;
                Insert(root, val);
                break;
            case 2:
                cout << "Inorder traversal: ";
                InOrder(root);
                cout << endl;
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }

    return 0;
}
