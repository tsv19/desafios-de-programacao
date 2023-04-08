#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;

    map<ll, ll> m;

    for (ll i = 0; i < n; i++) {
        ll x, c;
        cin >> x >> c;

        if (m.count(c) == 0){
            m[c] = x;
        }
        else if (m[c] <= x) {
            m[c] = x;
        }
        else if (m[c] > x) {
            cout << "NO\n"; 
            return 0;
        }
    }

    cout << "YES\n";
}