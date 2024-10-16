#include <iostream>
using namespace std;

bool isSubsetSum(int set[], int n, int sum) {
    // Create a 2D array to store solutions of subproblems
    bool dp[n+1][sum+1];

    // If sum is 0, we can always achieve it with an empty subset
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // If sum is not 0 and set is empty, no solution
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    // Fill the subset table in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            // If the current element is greater than the sum, ignore it
            if (set[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                // Check if sum can be obtained by including or excluding the current element
                dp[i][j] = dp[i-1][j] || dp[i-1][j-set[i-1]];
        }
    }

    return dp[n][sum];
}

int main() {
    int set1[] = {3, 34, 4, 12, 5, 2};
    int sum1 = 9;
    int n1 = sizeof(set1)/sizeof(set1[0]);
    if (isSubsetSum(set1, n1, sum1))
        cout << "True\n";
    else
        cout << "False\n";

    int set2[] = {3, 34, 4, 12, 5, 2};
    int sum2 = 30;
    int n2 = sizeof(set2)/sizeof(set2[0]);
    if (isSubsetSum(set2, n2, sum2))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}
