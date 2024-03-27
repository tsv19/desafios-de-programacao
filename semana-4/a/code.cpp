#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >>t;

    while (t--){
        int lucro = 0, P, H, F, D, C;
        cin >> P >> H >> F >> D >> C;

        if ( D > C ){
            while ( P > 1 && H > 0 ){
                H--;
                P -= 2;
                lucro += D;
            }

            while ( P > 1 && F > 0 ){
                F--;
                P -= 2;
                lucro += C;
            }
        }
        else {
            while ( P > 1 && F > 0 ){
                F--;
                P -= 2;
                lucro += C;
            }

            while ( P > 1 && H > 0 ){
                H--;
                P -= 2;
                lucro += D;
            }
        }
        
        cout << lucro << '\n';
    }
}