#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    list<ll> l;
    auto posi = l.begin();
    int n;

    cin >> n;

    for (int i = 0; i < n; i++){
        string o;
        cin >> o;

        if ( o == "m" ){
            ll d;
            cin >> d;

            advance(posi, d);
        }
        else if ( o == "i" ){
            int q;
            ll t;
            cin >> q >> t;

            for (int j = 0; j < q; j++){
                l.insert(posi, t);
                --posi;
            }
        }
        else if ( o == "d" ){
            auto posi_del = posi;
            ++posi;
            l.erase(posi_del);
        }
        else if ( o == "q" ){
            cout << *posi << "\n";
        }
    }
}