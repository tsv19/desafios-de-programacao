#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

ll ans = INT64_MAX;
int n;

void backt(ll k, vector <ll> a, vector<vector<ll>> subsets){
    if ( a.size() == 0 ){
        ll calculo = 0;

        for (int i = 0; i < subsets.size(); i++){
            ll ors = 0;

            for (int j = 0; j < subsets[i].size(); j++){
                ors |= subsets[i][j];
            }

            calculo ^= ors;
        }

        ans = min(ans, calculo);

        return;
    }


    ll val = a.back();
    a.pop_back();

    for (int i = k; i < subsets.size(); i++){
        subsets[i].push_back(val);

        if (i != 0 && subsets[i - 1].empty()){
            subsets[i].pop_back();
            return;
        }

        backt(i, a, subsets);
        subsets[i].pop_back();
    }
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;

    vector <ll> a(n);

    for (auto &ai : a) cin >> ai;

    vector<vector<ll>> subsets;
    
    for (auto ai : a) subsets.push_back(vector<ll>());

    backt(0, a, subsets);

    cout << ans << '\n';
}