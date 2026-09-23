#include <bits/stdc++.h>
using namespace std;

int minCoins(vector<int>& coins, int n, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
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

    int result = minCoins(coins, n, amount);

    if (result != -1)
        cout << "Minimum coins required: " << result << endl;
    else
        cout << "It is not possible to make the amount with given coins." << endl;

    return 0;
}
