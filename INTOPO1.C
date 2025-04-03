#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1)
        return '\0';
    else
        return stack[top--];
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j;
    char token;

    i = j = 0;

    while ((token = infix[i++]) != '\0') {
        if (isalnum(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(token);
        } else if (token == ')') {
            while ((token = pop()) != '(')
                postfix[j++] = token;
        } else {
            while (precedence(token) <= precedence(stack[top]) && top != -1) {
                postfix[j++] = pop();
            }
            push(token);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[SIZE];
    char postfix[SIZE];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
