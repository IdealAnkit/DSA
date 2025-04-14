#include<iostream>
using namespace std;


void display(int a[],int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<<a[i]<<" ";
    }
        cout<<endl;
}
void Swap(int* k,int* l)
{
    int temp;
    temp=*k;
    *k=*l;
    *l=temp;
}
void BubbleSort(int a[], int size)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if (a[j]>a[j+1])
                Swap(&a[j],&a[j+1]);
        }
        
    }
    
}

int main()
{
    int a[]={5,7,1,9,3,4,8,6,5,2};
    int size= sizeof(a)/sizeof(a[0]);
    cout<<"Array before sorting :- ";
    display(a,size);
    BubbleSort(a,size);
    cout<<"Array after sorting :- ";
    display(a,size);
    
    return 0;
}