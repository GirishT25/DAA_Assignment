// Implement a problem of number of zeroes. 
// Statement: Given an array of 1s and 0s which has all 
// 1s first followed by all 0s? Find the number of 0s. 
// Count the number of zeroes in the given array. 
// Input: arr[] = {1, 1, 1, 1, 0, 0}                     Output: 2 
// Input: arr[] = {1, 0, 0, 0, 0}                          Output: 4 
#include<iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int a[size];
    cout << "Enter " << size << " elements (only 0s and 1s): ";
    for(int i = 0; i < size; i++) {
        cin >> a[i];
    }

    int low = 0;
    int high = size - 1;
    int mid;

    while(low <= high) {
        mid = (low + high) / 2;
        if(a[mid] == 1) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    int count = size - low;
    cout << "Number of zeros are: " << count;

    return 0;
}
