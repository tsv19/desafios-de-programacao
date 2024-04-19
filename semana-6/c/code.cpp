#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n;
    cin >> n;
    multiset<ll> towers;

    ll x;
    while (n--){
        cin >> x;

        auto itr = towers.upper_bound(x);
        if ( itr != towers.end() ){
            towers.erase(itr);
            towers.insert(x);
        }
        else towers.insert(x);
    }

    cout << towers.size() << "\n";
}