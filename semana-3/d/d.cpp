#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll ans = INT64_MAX;

void ba(vector<ll> val, ll ini, vector<vector<ll>> ss) {
    if (val.size() == 0) {
        ll xors = 0;
        
        // cout << "ss: ";
        for (size_t i = 0; i < ss.size(); i++) {
            ll s = 0;
            // cout << "[";
            for (size_t j = 0; j < ss[i].size(); j++) {
                s |= ss[i][j];
                cout << ss[i][j] << " ";
            }
            // cout << "] | ";
            xors ^= s;
        }
        // cout << endl;
        
        ans = min(ans, xors);
        return;
    }

    int a = val.back();
    val.pop_back();
    for (size_t i = ini; i < ss.size(); i++) {
        ss[i].push_back(a);

        if ( i != 0 && ss[i - 1].empty() && ss[i].size() == 1 ){
            ss[i].pop_back();
            return;
        }

        ba(val, i, ss);
        ss[i].pop_back();
    }
}


int main() {
    int n;
    cin >> n;

    vector<ll> val;
    while (n--) {
        ll a;
        cin >> a;
        val.push_back(a);
    }

    vector<vector<ll>> ss;
    for (size_t i = 0; i < val.size(); i++) {
        ss.push_back(vector<ll>());
    }

    ba(val, 0, ss);

    cout << ans << '\n';
}