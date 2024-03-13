#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++){
        ll l;
        int n;

        cin >> l >> n;

        ll max_t = 0, min_t = 0;

        for (int j = 0; j < n; j++){
            ll p;
            cin >> p;

            ll esq = p;
            ll dir = l - p;

            min_t = max(min_t, min(esq, dir));
            max_t = max(max_t, max(esq, dir));
        } 

        cout << min_t << " " << max_t << "\n";
    }
}