#include <bits/stdc++.h>
using namespace std;

int n = 0;
int rn = 0;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;

    int d = 0;
    for (int a = 1; a <= n; a++)
        for (int b = a; b <= n; b++)
            if ( n - (a+b) >= b ) d++;

    cout << d << endl;
}