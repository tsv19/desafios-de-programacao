#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n;
    cin >> n;

    map<ll, vector<ll>> lt;
    ll l, d;
    for (ll i = 0; i < n; i++)
    {
        cin >> l >> d;
        lt[d].push_back(l);
    }

    for (auto &v : lt)
    {
        sort(v.second.begin(), v.second.end());
    }

    ll td = 0;
    ll i = 0;
    for (auto &v : lt)
    {
        vector<ll> curv = v.second;
        ll curd = v.first;
        while (i < curd && !curv.empty())
        {
            td += curv.back();
            curv.pop_back();
            i++;
        }
    }

    cout << td << "\n";
}