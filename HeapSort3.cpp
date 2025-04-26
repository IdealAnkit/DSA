#include<iostream>
using namespace std;
void heapify(int arr[],int size,int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<=size && arr[left]>arr[largest]){
        largest = left;
    }
    if(right<=size && arr[right]>arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr,size,largest);
    }
}

void heapShot(int arr[],int size){
    while(size>0){
        // first swap the first element to last element
        swap(arr[0],arr[size]);
        // decrease size
        size--;

        heapify(arr,size,0);
    }
}


int main(){

    int arr[] = {5, 7, 1, 9, 3, -4, 8, 6, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);


    // Building heap

    for(int i=n/2 ;i>=0;i--){
        heapify(arr,n-1,i);
    }

    // Heap Sort
    heapShot(arr,n-1);

    // Printing Array
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}