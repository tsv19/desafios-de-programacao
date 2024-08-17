#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<ll>> adj;
vector<bool> visited;


void print(vector<bool> v, string s = ""){
    cout << s << ": ";
    for (auto i : v) cout << i << " ";
    cout << endl;
}

void explore(ll x){
    visited[x] = true;
    ll c = 1;
    for (ll v : adj[x]) if (!visited[v]) explore(v);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;
    adj.resize(n);
    
    visited = vector<bool>(n, false);
    
    for (ll i = 0; i < m; i++){
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll components = 0;
    for (ll i = 0; i < n; i++){
        if (!visited[i]){
            components++;
            explore(i);
        }
    }

    cout << components << "\n";
}