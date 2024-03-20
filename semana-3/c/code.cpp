#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a, b, res;

void gen(vector<ll> s, vector<ll> primo){
    if (primo.empty()){
        if (!s.empty()){
            ll multDaVez = 1;
            for (auto p : s) multDaVez *= p;

            ll ini = (a % multDaVez == 0) ? a : a + (multDaVez - a % multDaVez);
            ll fim = (b % multDaVez == 0) ? b : b - (b % multDaVez);
            ll qMultiplos = ((fim - ini) / multDaVez) + 1;
            res -= ((s.size() % 2) == 1) ? qMultiplos : -qMultiplos;
        }
        return;
    }

    ll x = primo.back();
    primo.pop_back();
    gen(s, primo);
    s.push_back(x);
    gen(s, primo);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;

    cin >> a >> b;
    cin >> n;

    vector<ll> primo(n);
    for (auto &p : primo) cin >> p;

    res = b - a + 1;

    vector<ll> s;
    gen(s, primo);

    cout << res << endl;
}