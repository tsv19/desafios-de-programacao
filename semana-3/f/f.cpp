#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    map <ll, ll> mr;
    set <ll> res;
    
    vector <ll> a;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end());

    int meio = -1;
    ll q = 0;
    ll qp = 0;
    int cont = 0;
    for (int i = 0; i < n-1; i++) {
        q = a[i+1] / a[i];
        
        if ( q != qp && i != 0 ) {
            meio = i;
            cont++;
        }
        
        mr[q]++;
        qp = q;
    }

    if (meio != -1) {
        ll max = 0;
        ll chave = 0;
        for (auto it = mr.begin(); it != mr.end(); it++) {
            if (it->second > max) {
                max = it->second;
                chave = it->first;
            }
        }

        q = chave;

        if ( cont == 1 && meio == n-2){ 
            meio++;
        }

        res.insert(a[meio] / q);
    }
    else {
        res.insert(a[a.size()-1] * q);

        if (a[0] % q == 0) {
            res.insert(a[0] / q);
        }
    }

    for (auto it = res.begin(); it != res.end(); it++) {
        cout << *it << "\n";
    }
}