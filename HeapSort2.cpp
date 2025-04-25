#include <iostream>
using namespace std;
//not good program
class Heap
{
public:
    int arr[100];
    int size;

    Heap()
    {
        arr[0] = -1;
        size = 0;
        int value = 0;
    }
};
void Heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }

    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        Heapify(arr, n, largest);
    }
}
void SortHeap(int arr[], int n)
{
    int size = n;

    while (size > 1)
    {
        int temp = arr[1];
        arr[1] = arr[size];
        arr[size] = temp;
        size--;
        Heapify(arr, size, 1);
    }
}

int main()
{
    int arr[] = {-1, 60, 45, 40, 58, 55,4,1,0,0,4,6,0,34,0,0,0};

    int n = sizeof(arr)/sizeof(arr[0])-1;
    for (int i = n / 2; i > 0; i--)
    {
        Heapify(arr, n, i);
    }

    cout << "arry before sorting:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    SortHeap(arr, n);
    cout << "array after sorting:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}