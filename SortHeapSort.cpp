#include <iostream>
using namespace std;
void display(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void maxHeapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest])
    {
        largest = left;
    }
    if (right < n && a[right] > a[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(a[largest], a[i]);
        maxHeapify(a, n, largest);
    }
}
void HeapSort(int a[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        maxHeapify(a, i, 0);
    }
}
int main()
{
    int a[] = {5, 7, 1, 9, 3, -4, 8, 6, 5, 2};
    int size = sizeof(a) / sizeof(a[0]);

    //CREATING HEAP
    int n = size;
    for (int i = n / 2 -1 ; i >= 0; i--)
    {
        maxHeapify(a, n, i);
    }

    cout << "Array before sorting :- ";
    display(a, size);
    HeapSort(a, size);
    cout << "Array after sorting :- ";
    display(a, size);
    return 0;
}