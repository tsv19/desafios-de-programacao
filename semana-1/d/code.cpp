#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<ll> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v [i];
    }

    ll diferenca = 0;
    ll maior = v[0];

    for (int i = 1; i < n; i++) {
        if (maior > v[i]){
            diferenca += maior - v[i];
        }
        else {
            maior = v[i];
        }
    }

    cout << diferenca << "\n";
}
