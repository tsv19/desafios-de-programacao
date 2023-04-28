#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    int p, h, f, d, c;

    while (t--) {
        cin >> p >> h >> f >> d >> c;

        int ans = 0;

        // pega com maior valor
        if ( d > c ){
            while ( p > 1 && h > 0){
                h--;
                p -= 2;
                ans += d;
            }
            while ( p > 1 && f > 0){
                f--;
                p -= 2;
                ans += c;
            }
        }
        else {
            while ( p > 1 && f > 0){
                f--;
                p -= 2;
                ans += c;
            }
            while ( p > 1 && h > 0){
                h--;
                p -= 2;
                ans += d;
            }
        }

        cout << ans << "\n";
    }
}