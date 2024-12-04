// Implement a problem of maximize Profit by trading 
// stocks based on given rate per day. 
// Statement: Given an array arr[] of N positive integers 
// which denotes the cost of selling and buying a stock on 
// each of the N days. The task is to find the maximum 
// profit that can be earned by buying a stock on or selling 
// all previously bought stocks on a particular day. 
// Input: arr[] = {2, 3, 5}                      Output: 5  
// Input: arr[] = {8, 5, 1}                      Output: 0  
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



