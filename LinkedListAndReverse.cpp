#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

Node* append(Node* head, int data) {
    if (!head) {
        return createNode(data);
    }

    Node* current = head;
    while (current->next) {
        current = current->next;
    }

    current->next = createNode(data);
    return head;
}

void display(Node* head) {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    while (current) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

int main() {
    Node* linkedList = nullptr;


    linkedList = append(linkedList, 1);
    linkedList = append(linkedList, 2);
    linkedList = append(linkedList, 3);
    linkedList = append(linkedList, 4);

    std::cout << "Original Linked List:" << std::endl;
    display(linkedList);

    linkedList = reverse(linkedList);

    std::cout << "Reversed Linked List:" << std::endl;
    display(linkedList);

    return 0;
}