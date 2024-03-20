#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;

    cin >> n;

    vector<ll> a(n);
    set<ll> res;

    for (auto &x : a) cin >> x;

    sort(a.begin(), a.end());

    map<ll, ll> qCounter;

    // se perdeu no meio
    ll q = 0, qAnterior = 0;
    int perdeuMeio = -1;
    int cont = 0;
    for (int i = 0; i < n - 1; i++){
        q = a[i + 1] / a[i];

        if (q != qAnterior && i != 0){
            perdeuMeio = i;
            cont++;
        }

        qCounter[q]++;
        qAnterior = q;
    }

    // no meio
    if (perdeuMeio != -1){
        int max = 0;
        int key = -1;

        for (auto it = qCounter.begin(); it != qCounter.end(); it++){
            if (it->second > max){
                max = it->second;
                key = it->first;
            }
        }

        q = key;

        if (cont == 1 && perdeuMeio == n - 2){
            perdeuMeio++;
        }

        res.insert(a[perdeuMeio] / q);
    }
    else {

        // no fim
        res.insert(a[a.size() - 1] * q);

        // no inicio
        if (a[0] % q == 0){
            res.insert(a[0] / q);
        }
    }

    for (auto &x : res){
        cout << x << endl;
    }
}