#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;

    cin >> n >> k;

    ll u, t;
    string format;
    
    vector<tuple<ll, int, ll>> v;
    tuple<ll, int, ll> tp;

    for (int i = 0; i < n; i++) {
        cin >> u >> format >> t;

        int ind;
        if (format == "TMP"){
            ind = 1;
        }
        else if (format == "OGG"){
            ind = 2;
        }
        else if (format == "CPP"){
            ind = 3;
        }

        tp = make_tuple(u, ind, t);
        v.push_back(tp);
    }

    sort(v.begin(), v.end(), [](const tuple<ll, int, ll>& a, const tuple<ll, int, ll>& b) {
        if ( get<0>(a) == get<0>(b) ){
            if ( get<1>(a) == get<1>(b) ){
                return get<2>(a) > get<2>(b);
            }

            return get<1>(a) < get<1>(b);
        }

        return get<0>(a) < get<0>(b);
    });

    ll sum = 0;
    for (int i = 0; i < k; i++) {
        sum += get<2>(v[i]);
    }
    cout << sum << "\n";
}