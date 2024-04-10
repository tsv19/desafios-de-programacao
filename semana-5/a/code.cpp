#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

#define A 0
#define B 1
#define C 2

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n, soma = 0;
    cin >> n;

    vector<tuple<ll,ll,ll>> atividades(n);

    for (auto &x : atividades){
        cin >> get<0>(x) >> get<1>(x) >> get<2>(x);
    }

    vector<vector<ll>> mem(n, vector<ll>(3, 0));

    mem[0][A] = get<A>(atividades[0]);
    mem[0][B] = get<B>(atividades[0]);
    mem[0][C] = get<C>(atividades[0]);

    for (int i = 1; i < n; i++){
        mem[i][A] = max(mem[i-1][B] + get<A>(atividades[i]), mem[i-1][C] + get<A>(atividades[i]));
        mem[i][B] = max(mem[i-1][A] + get<B>(atividades[i]), mem[i-1][C] + get<B>(atividades[i]));
        mem[i][C] = max(mem[i-1][A] + get<C>(atividades[i]), mem[i-1][B] + get<C>(atividades[i]));
    }

    cout << max({mem[n-1][A], mem[n-1][B], mem[n-1][C]}) << '\n';
}