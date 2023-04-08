#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;

    stack <pair<ll, char>> s;

    for (ll i = 0; i < n; i++) {
        ll altura;
        char direcao;
        cin >> altura >> direcao;

        pair<ll, char> parNovo = make_pair(altura, direcao);

        if ( s.empty() ){ 
            s.push(parNovo);

            // quebra o laco se comeca com O
            if ( direcao == 'O' ) break;
        }
        else {
            pair<ll, char> par = s.top();

            if ( par.first < parNovo.first ) break;

            if ( par.first == parNovo.first && parNovo.second == 'L' ) break;

            if ( par.first == parNovo.first && parNovo.second == 'O' ){
                s.pop();
            }
        }
    }

    if ( s.empty() ){
        cout << "S\n";
    }
    else {
        cout << "N\n";
    }
}