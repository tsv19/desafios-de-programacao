#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<ll>> adj;
vector<bool> visited;

ll maxDepth = 0;
ll maxNode = 0;


void explore(ll u, ll d){
    if (d > maxDepth){
        maxDepth = d;
        maxNode = u;
    }

    visited[u] = true;
    ll c = 1;
    for (ll v : adj[u]) 
        if (!visited[v]) explore(v, d + 1);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n;
    cin >> n;
    adj.resize(n + 1);
    visited = vector<bool>(n + 1, false);

    for (ll i = 0; i < n - 1; i++){
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    explore(1, 0);
    visited = vector<bool>(n + 1, false);
    explore(maxNode, 0);

    cout << maxDepth << "\n";
}