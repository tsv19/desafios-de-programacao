#include <bits/stdc++.h>

using namespace std;

using ll =  long long;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll pilha1 = 0, pilha2 = 0; 
    int n;
    cin >> n;

    // while (n--){
    //     ll x;
    //     cin >> x;

    //     max(pilha1-pilha2, pilha2-pilha1);
    // }


    priority_queue<ll> pq;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        pq.push(x);
    }


    ll a = 0;
    while (!pq.empty()) {
        ll x = pq.top();
        pq.pop();

        a = a - x;

        if ( a < 0 ){
            a *= -1;
        } 

        cout << a << " " << x << endl;
    }

    cout << a << endl;
}