#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int M = 1e9;
vector<ll> factors;


void print(vector<ll> v, string s = ""){
    cout << s << ": ";
    for (auto i : v) cout << i << " ";
    cout << endl;
}

ll fastPow(ll a, ll b){
    if (b == 0) return 1;
    if (b == 1) return a;

    ll res = fastPow(a, b/2);
    res = (res * res) % M;
    
    if (b % 2) res = (res * a) % M;
    
    return res;
}

void factorize(ll n){
    for (ll i = 2; i * i <= n; i++){
        while (n % i == 0){
            n /= i;
            factors.push_back(i);
        }
    }

    if (n > 1) factors.push_back(n);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll t;

    cin >> t;

    while (t--){
        ll k, n = 1;
        cin >> k;

        while (k--){
            ll p, e;
            cin >> p >> e;
            n *= fastPow(p, e);
        }

        n--;
        factors.clear();
        factors.resize(0);
        factorize(n);
        sort(factors.begin(), factors.end(), greater<ll>());

        ll prev = -1;
        ll cnt = 0;
        for (auto i : factors){
            if (i == prev) cnt++;
            else {
                if (prev != -1) cout << prev << " " << cnt << "\n";
                
                prev = i;
                cnt = 1;
            }
        }

        cout << prev << " " << cnt << "\n";
    }
}