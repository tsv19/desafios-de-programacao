#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n;
    cin >> n;

    ll s = 0;
    while (n--){
        ll caju = 0;
        cin >> caju;

        if ( caju > 10 ){
            s += caju - 10;
        }
    }

    cout << s << "\n";
}
