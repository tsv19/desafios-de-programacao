#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll minDiff = LLONG_MAX;

int n;


void calculaDiff(vector<ll> &v, vector<bool> &used){
    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++){
        if (used[i]){
            sum1 += v[i];
        }
        else {
            sum2 += v[i];
        }
    }

    minDiff = min(minDiff, abs(sum1-sum2));
}

void backt(int x, vector<ll> &v, vector<bool> &used){
    if ( x == n ){
        calculaDiff(v, used);
        return;
    }

    for (int i = x; i < n; i++){
        used[i] = true;
        backt(i+1, v, used);
        used[i] = false;
    }
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;

    vector<ll> v(n);
    vector<bool> used(n);


    for (auto &x : v){
        cin >> x;
    }

    for (int i = 0; i < n; i++){
        backt(i, v, used);
        used[i] = true;
    }

    cout << minDiff << endl;
}