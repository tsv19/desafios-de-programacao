#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll a, b, c;

    cin >> a >> b >> c;

    if (( a == 0 && b == 0) || ( a == 1 && b == 1 )){
        cout << -c << "\n";
    }
    else if ( b == 1 ) {
        cout << - 1 - c << "\n";
    }
    else {
        cout << a - b * c << "\n";
    }
}