/*
Implement a problem of minimum work to be done 
per day to finish given tasks within D days problem. 
Statement: Given an array task[] of size N denoting 
amount of work to be done for each task, the problem 
is to find the minimum amount of work to be done on 
each day so that all the tasks can be completed in at 
most D days. Note: On one day work can be done for 
only one task. 
Input: task[] = [3, 4, 7, 15],  D = 10                     
Output: 4 
Input: task[] = [30, 20, 22, 4, 21], D = 6              
Output: 22
*/
#include <iostream>
using namespace std;

int maxProfit(int arr[], int N) {
    
    int minPrice = arr[0];
    
        int maxProfit = 0;
    
    
    for (int i = 1; i < N; ++i) {
                int profit = arr[i] - minPrice;
        
        
        if (profit > maxProfit) {
            maxProfit = profit;
        }
        
        
        if (arr[i] < minPrice) {
            minPrice = arr[i];
        }
    }
    
    return maxProfit;
}

int main() {

    int arr1[] = {2, 3, 5};
    int N1 = 3;
    cout << "Maximum profit for arr1: " << maxProfit(arr1, N1) << endl;

    int arr2[] = {8, 5, 1};
    int N2 = 3;
    cout << "Maximum profit for arr2: " << maxProfit(arr2, N2) << endl;
    
    return 0;
}



