#include <bits/stdc++.h>
using namespace std;

int countWays(vector<int>& coins, int n, int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int j = 0; j < n; j++) {
        for (int i = coins[j]; i <= amount; i++) {
            dp[i] += dp[i - coins[j]];
        }
    }

    return dp[amount];
}

int main() {
    int n;
    cout << "Enter number of coin denominations: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter " << n << " coin denominations: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    int amount;
    cout << "Enter the amount to make: ";
    cin >> amount;

    cout << "Number of ways to make " << amount << ": "
         << countWays(coins, n, amount) << endl;

    return 0;
}
