#include <iostream>
using namespace std;

bool isSubsetSum(int set[], int n, int sum) {
    
    bool dp[n+1][sum+1];

    
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (set[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
        
                dp[i][j] = dp[i-1][j] || dp[i-1][j-set[i-1]];
        }
    }

    return dp[n][sum];
}

int main() {
    int set1[] = {3, 34, 4, 12, 5, 2};
    int sum1 = 9;
    int n1 = 6;
    if (isSubsetSum(set1, n1, sum1))
        cout << "True\n";
    else
        cout << "False\n";

    int set2[] = {3, 34, 4, 12, 5, 2};
    int sum2 = 30;
    int n2 = 6;
    if (isSubsetSum(set2, n2, sum2))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}
