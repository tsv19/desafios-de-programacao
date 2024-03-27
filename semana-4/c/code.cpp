#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    int soma = 0;
    while (n--){
        int x;
        cin >> x;

        if ( x > 10 ){ 
            soma += x - 10;
        }
    }

    cout << soma << '\n';
}