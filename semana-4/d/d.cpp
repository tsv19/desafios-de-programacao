#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll t;
    cin >> t;

    for (int i = 0; i < t; i++){
        string s;
        cin >> s;

        ll d = 0;
        ll g = 0;
        for (auto &p : s ){
            if ( d == 0 && p == '_' ){
                g++;
                d = 3;
            }

            if (d != 0){
                d--;
            }
        }

        cout << "Caso " << i + 1 << ": " << g << "\n";
    }
}
