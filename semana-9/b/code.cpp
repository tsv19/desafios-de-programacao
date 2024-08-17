#include <bits/stdc++.h>
using namespace std;

#define edge pair<ll, ll>
using ll = long long;
long long pinf = 1987654321987654321;


const int N = 1e5 + 15;

vector<vector<edge>> g(N);
vector<ll> lot;
vector<ll> d(N, pinf), vis(N);


void dijkstra(int src){
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;

    d[src] = 0;
    Q.push({0, src});

    while (!Q.empty()){
        auto [c, u] = Q.top();
        Q.pop();
        if (vis[u])
            continue;

        vis[u] = true;
        
        for (auto [v, w] : g[u])
            if (d[v] > d[u] + w){
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n;
    cin >> n;
    lot.resize(n);

    for (ll i = 0; i < n; i++)
        cin >> lot[i];

    ll m;
    cin >> m;
    
    while (m--){
        ll x, y;
        cin >> x >> y;
        --x;
        --y;

        ll w = lot[y] - lot[x];
        g[x].push_back(edge(y, w));
    }

    ll q;
    cin >> q;
    dijkstra(0);

    while (q--){
        ll x;
        cin >> x;
        --x;
        ll lc = d[x];
        
        if ((lc < 3) || (lc >= pinf)) cout << "Não, Edsger...\n";
        else cout << lc << "\n";
    }
}