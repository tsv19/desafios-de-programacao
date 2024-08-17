#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void crivo(ll n){
    vector<bool> sieve(n, true);

    for (ll i = 2; i*i <= n; i++){
        if (sieve[i]){
            for (int j = i*i; j <= n; j += i){
                sieve[j] = false;
            }
        }
    }

    // for (int i = 2; i <= n; i++){
    //     if (sieve[i]){
    //         cout << i << " ";
    //     }
    // }
    // cout << '\n';

    int soma = 0;
    for (int i = 2; i <= n/2; i++){
        if (sieve[i] && sieve[n-i]){
            soma++;
        }
    }

    cout << soma << " \n";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n;

    cin >> n;
    crivo(n);
}