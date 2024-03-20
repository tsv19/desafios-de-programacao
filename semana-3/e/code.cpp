#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

set<int> s;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, a, b, c, d, e, f, sext = 0;

    cin >> n;
    while (n--) {
        int si;
        cin >> si;
        s.insert(si);
    }

    map<int, int> results;

    for (auto a : s) {
        for (auto b : s) {
            for (auto c : s) {
                results[(a * b) + c]++;
            }
        }   
    }

    for (auto d : s) {
        if (d == 0) continue;

        for (auto e : s) {
            for (auto f : s) {
                int val = d * (e + f);
                if ( results.count(val) ){
                   sext += results[val];
                }
            }
        }   
    }

    cout << sext << endl;
}