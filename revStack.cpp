#include <iostream>
#include <stack>

void insertAtBottom(std::stack<int>& s, int x) {
    // Base case: If the stack is empty, push the element
    if (s.empty()) {
        s.push(x);
        return;
    }

    // Remove the top element
    int temp = s.top();
    s.pop();

    // Recursive call
    insertAtBottom(s, x);

    // Push the removed element back
    s.push(temp);
}

void reverseStack(std::stack<int>& s) {
    // Base case: If the stack is empty, return
    if (s.empty()) {
        return;
    }

    // Remove the top element
    int temp = s.top();
    s.pop();

    // Reverse the remaining stack
    reverseStack(s);

    // Insert the removed element at the bottom of the reversed stack
    insertAtBottom(s, temp);
}

int main() {
    std::stack<int> s;

    // Push elements onto the stack
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    std::cout << "Original stack: ";
    std::stack<int> temp = s; // Create a temporary stack to display the original stack
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << std::endl;

    // Reverse the stack
    reverseStack(s);

    std::cout << "Reversed stack: ";
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;

    return 0;
}