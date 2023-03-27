#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

int main(){
    int n;
    vector<int> a;
    int x;

    ll r = 0;

    while (cin >> n){
        for (int i = 0; i < n; i++){
            cin >> x;
            a.push_back(x);
        }

        for (int i = 0; i < n/2; i++){
            cin >> x;
            r += abs(a[i] + a[n-i-1] - x);
        }

        cout << r << '\n';
        a.clear();
        r = 0;
    }
}
