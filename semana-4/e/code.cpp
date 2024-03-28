#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll soma = 0;
    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;

    vector<ll> Av(A), Bv(B), Cv(C);

    for (ll i = 0; i < A; i++) {
        cin >> Av[i];
    }
    for (ll i = 0; i < B; i++) {
        cin >> Bv[i];
    }
    for (ll i = 0; i < C; i++) {
        cin >> Cv[i];
    }

    sort(Av.rbegin(), Av.rend());
    sort(Bv.rbegin(), Bv.rend());
    sort(Cv.rbegin(), Cv.rend());

    vector<ll> v;
    for (ll i = 0; i < X; i++) {
        v.push_back(Av[i]);
    }
    for (ll i = 0; i < Y; i++) {
        v.push_back(Bv[i]);
    }
    for (ll i = 0; i < C; i++) {
        v.push_back(Cv[i]);
    }

    sort(v.rbegin(), v.rend());

    for (ll i = 0; i < X + Y; i++) {
        soma += v[i];
    }

    cout << soma << endl;
}
