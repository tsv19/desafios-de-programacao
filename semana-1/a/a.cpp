#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

int main() {
    int n;
    cin >> n;

    while (n--) {
        string a, b;
        cin >> a >> b;

        ll x = ll(a[a.length() - 1]);
        ll y = ll(b[b.length() - 1]);

        if (( x + y ) % 2 == 1)
            cout << "NAO PARCEIROS\n";
        else
            cout << "PARCEIROS\n";
    }
}