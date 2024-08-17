#include <bits/stdc++.h>
using namespace std;

using ll = long long;

long long pinf = 1987654321987654321;
long long minf = -9223372036854775807;


int main(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> d(n, vector<ll>(n, pinf));
    
    while (m--){
        ll u, v, w;
        cin >> u >> v >> w;

        if ((d[u][v] != pinf) || (d[v][u] != pinf)){
            d[u][v] = min(min(d[u][v], w), d[v][u]);
            d[v][u] = d[u][v];
        } 
        else {
            d[u][v] = w;
            d[v][u] = w;
        }
    }

    for (ll u = 0; u < n; u++)
        d[u][u] = 0;

    for (ll m = 0; m < n; m++)
        for (ll u = 0; u < n; u++)
            for (ll v = 0; v < n; v++)
                d[u][v] = min(d[u][v], d[u][m] + d[m][v]);

    ll distMin = pinf;
    for (ll j = 0; j < n; j++){
        ll maxDist = -pinf;

        for (ll i = 0; i < n; i++)
            maxDist = max(maxDist, d[i][j]);

        distMin = min(maxDist, distMin);
    }

    cout << distMin << "\n";
}