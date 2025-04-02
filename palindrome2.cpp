#include<iostream>
using namespace std;
int main()
{
    int i,rev=0,orig;
    cout<<"enter the palindrome number";
    cin>>i;
    orig=i;
    for( ;i>0;i=i/10)
    {

        rev=rev*10+i%10;
    }
    if(orig==rev)
    {
        cout<<"number is palindrome";
    }
        else
        {

            cout<<"number is not palindrome";

        }
        return 0;

}