#include <iostream>
#include <ctype.h>
using namespace std;

#define sz 100

char stack[sz];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    if (top == -1)
        return '\0';
    else
        return stack[top--];
}

int precedence(char op)
{
    switch (op)
    {
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

void ItoP(char InFix[], char PostFix[])
{
    int i, j;
    char token;
    i = 0;
    j = 0;
    while ((token = InFix[i++]) != '\0')
    {
        if (isalnum(token))
            PostFix[j++] = token;
        else if (token == '(')
            push(token);
        else if (token == ')')
        {
            while ((token = pop()) != '(')
                PostFix[j++] = token;
        }
        else
        {
            while (precedence(token) <= precedence(stack[top]) && top != -1)
                PostFix[j++] = pop();
            push(token);
        }
    }
    while (top != -1)
        PostFix[j++] = pop();
    PostFix[j] = '\0';
}

int main()
{
    char InFix[sz], PostFix[sz];
    cout << "Enter infix expression : ";
    cin >> InFix;
    ItoP(InFix, PostFix);
    cout << "Postfix Expression : " << PostFix;

    return 0;
}