#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    if (str1 == str2) {
        cout << "The strings are equal." << endl;
    } else if (str1 < str2) {
        cout << "The first string is lexicographically smaller than the second." << endl;
    } else {
        cout << "The first string is lexicographically greater than the second." << endl;
    }

    return 0;
}
