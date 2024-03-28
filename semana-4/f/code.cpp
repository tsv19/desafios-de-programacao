#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<ll> p(n);

    for (ll i = 0; i < n; i++) cin >> p[i];

    sort(p.begin(), p.end());

    ll valMedio;
    
    if (n % 2 == 0) valMedio = p[n/2 - 1];
    else valMedio = p[n/2];
     
    ll diff = 0;
    for (int i = 0; i < n; i++) diff += abs(valMedio - p[i]);

    cout << diff << '\n';
}
