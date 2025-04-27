#include<stdio.h>

int main()
{
    char Ankit[100], AnkitReverse[100];
    int top, count=0;
    printf("Enter the string : ");
    gets(Ankit);
    while (Ankit[count]!='\0')
        count++;
    top=count-1;
    for (int i = 0; i < count; i++)
    {
        AnkitReverse[i]=Ankit[top];
        top--;
    }
    printf("%s",AnkitReverse);
    getchar();
    return 0;
}