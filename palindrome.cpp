#include<iostream>
using namespace std;
int main()
{
    int i,rev=0,orig;
    cout<<"enter the palindrome number - ";
    cin>>i;
    orig=i;
    while(i>0)
    {
        rev=(rev*10)+i%10;
        i=i/10;
    }
    if(orig==rev)
        cout<<"Given number is palindrome";
        else
            cout<<"Given number is not palindrome";
        return 0;

}