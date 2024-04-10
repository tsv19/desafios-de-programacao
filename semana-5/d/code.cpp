#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

map<ll, ll> F;


ll f(ll n){
    if ( F.count(n) == 1 ) return F[n];
    return F[n] = f(n/2) + f(n/3);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n;
    cin >> n;

    F[0] = 1;
    cout << f(n) << '\n';
}