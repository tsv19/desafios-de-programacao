#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    multiset<ll> h;
    vector<ll> t(m);

    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x; 
        h.insert(-x);
    }

    for (auto &i : t) cin >> i;

    multiset<ll, greater<ll>>::iterator it_lb;
    for (auto i : t) {
        it_lb = h.lower_bound(-i);
        
        if ( it_lb != h.end() ) {
            cout << -(*it_lb) << "\n";
            h.erase(it_lb);
        } 
        else cout << "-1\n";
    }
}