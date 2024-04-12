#include <bits/stdc++.h>

using namespace std;

using ll = int;

ll N, K, C;

vector<ll> v(11234);

vector<vector<ll>> memo(11234, vector<ll>(11234, INT32_MIN));

ll sol(ll i, ll k){
    // cout << "entrei com (i,k): (" << i << "," << k << ")\n";

    if ( i == N || i+k*C > N-1 ) {
        // cout << "fim" << endl << endl;
        return 0;
    }

    if ( k == 0 ) {
        return v[i] + sol(i+1, k);
    }

    if (memo[i][k] != INT32_MIN) {
        // cout << "ja calculei " << i << " e " << k << endl;
        return memo[i][k];
    }

    // cout << "block " << i << " | indo para " << i+C << endl;
    ll block = sol(i+C, k-1);
    
    // cout << "unblock " << i << " | indo para " << i+1 << endl;
    ll unblock = v[i] + sol(i+1, k);

    ll max_val = max(block, unblock);
    
    // cout <<"i = " << i << "| max(block,unblock) = (" << block << "," << unblock << ") = " << max_val << '\n';

    memo[i][k] = max_val;

    return max_val;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K >> C;

    for (ll i = 0; i < N; i++) {
        cin >> v[i];
    }

    ll solu = sol(0, K);
    cout << solu << '\n';
}