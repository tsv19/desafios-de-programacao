#include <bits/stdc++.h>
using namespace std;

using ll = long long;


void print(vector<ll> v, string s = ""){
    cout << s << ": ";
    for (auto i : v) cout << i << " ";
    cout << endl;
}

int main(){
    ll t;
    cin >> t;

    while (t--){
        ll n, d;
        cin >> n >> d;
        
        vector<ll> v;

        while ((n % d) > 0){
            v.push_back(n / d);
            ll a = n % d;
            n = d;
            d = a;
        }

        v.push_back(n / d);
        ll a = n % d;
        n = d;
        d = a;

        if (v.size() == 1){
            cout << "[" << v[0] << "]" << "\n";
            continue;
        }

        cout << "[";
        for (ll i = 0; i < v.size(); i++){
            if (i == 0) cout << v[i] << ";";
            else if (i == v.size() - 1) cout << v[i];
            else cout << v[i] << ",";
        }
        cout << "]" << '\n';
    }
}