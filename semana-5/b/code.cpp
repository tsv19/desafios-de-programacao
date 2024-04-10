#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

vector<ll> coins(5);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    coins = {1, 5, 10, 25, 50};

    vector<ll> dp(110001, 0);

    dp[0] = 1;

    for (int i = 0; i < 5; i++) {
        for (int j = coins[i]; j <= 110000; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    int n;
    while (cin >> n) {
        cout << dp[n] << '\n';
    }

    return 0;
}