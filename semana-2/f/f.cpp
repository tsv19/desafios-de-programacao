#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main() {
    ll n;
    cin >> n;

    list<ll> l;

    list<ll>::iterator it;
    bool first = true;

    for (ll i = 0; i < n; i++) {
        char op;

        cin >> op;

        if ( op == 'i' ){
            ll qtd = 0, val = 0;
            cin >> qtd >> val;

            if ( first ) {
                for (ll j = 0; j < qtd; j++) {
                    l.push_back(val);
                }
                
                it = l.begin();
                
                first = false;
            }
            else {
                for (ll j = 0; j < qtd; j++) {
                    l.insert(it, val);
                }
                for (ll j = 0; j < qtd; j++) {
                    it--;
                }
            }

        }
        else if ( op == 'm' ){
            ll qtd;
            cin >> qtd;

            if ( qtd > 0 )
                for (ll j = 0; j < qtd; j++) {
                    it++;
                }
            else
                for (ll j = 0; j < abs(qtd); j++) {
                    it--;
                }
        }
        else if ( op == 'd' ) {
            it = l.erase(it);
        }
        else if ( op == 'q' ){
            cout << *it << "\n";
        }

    }
}
