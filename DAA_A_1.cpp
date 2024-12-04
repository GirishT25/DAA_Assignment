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
