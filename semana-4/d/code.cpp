#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<string> strings(n);
    for (ll i = 0; i < n; i++) {
        cin >> strings[i];
    }

    sort(strings.begin(), strings.end(), [](const string& a, const string& b){
        return a + b < b + a;
    });

    string result = accumulate(strings.begin(), strings.end(), string(""));

    cout << result << '\n';
}