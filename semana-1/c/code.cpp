#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string materia;
    int h, m;

    while ( cin >> materia >> h >> m ){

        if (( h >= 10 && m > 0 ) || ( h > 10 )){
            cout << "Abel deve cancelar " << materia << "\n";
        }
        else {
            cout << "Abel deve cursar " << materia << "\n";
        }
    }
}