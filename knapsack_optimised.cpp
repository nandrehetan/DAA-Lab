#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum profit
int knapSack(int W, int wt[], int val[], int n)
{
    // Making and initializing dp array
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i < n + 1; i++) {
        for (int w = W; w >= 0; w--) {

            if (wt[i - 1] <= w)
                
                // Finding the maximum value
                dp[w] = max(dp[w],
                            dp[w - wt[i - 1]] + val[i - 1]);
        }
    }
    // Returning the maximum value of knapsack
    return dp[W];
}

// Driver code
int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    int profit[n], weight[n];
    cout << "Enter the profits and weights of " << n << " items:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Profit[" << i + 1 << "]: ";
        cin >> profit[i];
        cout << "Weight[" << i + 1 << "]: ";
        cin >> weight[i];
    }

    int W;
    cout << "Enter the capacity of knapsack: ";
    cin >> W;

    cout << "Maximum value in knapsack: " << knapSack(W, weight, profit, n) << endl;

    return 0;
}
