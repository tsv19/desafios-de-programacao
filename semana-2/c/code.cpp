#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n;
    cin >> n;

    set<ll> s;

    for (int i = 0; i < n; i++){
        ll x;
        cin >> x;

        if ( s.find(x - 1) != s.end() ){
            s.erase(x - 1);
        }
        
        s.insert(x);
    }

    cout << s.size() << "\n";
}