#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

int main(){
    int n;
    cin >> n;

    ll a, b;
    vector <pair<ll, ll>> v;

    ll c = 0;

    while (n--){
        cin >> a >> b;
        
        v.push_back(make_pair(a, 1));
        v.push_back(make_pair(b, -1));
    }

    sort(v.begin(), v.end());

    ll sum = 0;
    for (auto i : v){
        sum += i.second;
        c = max(c, sum);
    }

    cout << c << '\n';
}