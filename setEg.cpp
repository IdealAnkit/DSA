#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> mySet = {1, 2, 3, 4, 5, 23};

    // Search for the element 3
    auto it2 = mySet.find(3);

    // Check if the element was found
    if (it2 != mySet.end()) {
        cout << "Element found: " << &it2 << endl;
    } else {
        cout << "Element not found." << endl;
    }
    auto it1 = mySet.find(4);

    // Check if the element was found
    if (it1 != mySet.end()) {
        cout << "Element found: " << &it1 << endl;
    } else {
        cout << "Element not found." << endl;
    }
    auto its = mySet.find(5);

    // Check if the element was found
    if (its != mySet.end()) {
        cout << "Element found: " << &its << endl;
    } else {
        cout << "Element not found." << endl;
    }
    auto it = mySet.find(23);

    // Check if the element was found
    if (it != mySet.end()) {
        cout << "Element found: " << &it << endl;
    } else {
        cout << "Element not found." << endl;
    }

    // Search for an element not in the set
    it = mySet.find(10);
    if (it == mySet.end()) {
        cout << "Element not found." << endl;
    }
    int x;
    int *xs=&x;
    cout<<xs;
    return 0;
}
