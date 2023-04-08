#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v) cin >> x;

    vector<bool> t(n);
    for (auto &&x : t) x = false;

    ll tC = 0;
    for (auto &x : v){
        if (t[x - 1])
            t[x] = true;
        else {
            t[x - 1] = true;
            t[x] = true;
            tC++;
        }
    }

    cout << tC << "\n";
}