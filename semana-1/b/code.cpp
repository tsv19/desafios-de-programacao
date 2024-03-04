#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    vector<int> charVet(26, 0);

    string s;
    cin >> s;

    for (char c : s){
        charVet[c - 'A']++;
    }

    int impares = 0;
    int imparIndex = -1;
    for (int i = 0; i < 26; i++){
        impares += charVet[i] % 2;
        
        if ( charVet[i] % 2 && imparIndex == -1 ) imparIndex = i;
    }

    if ( s.length() % 2 == 0 ){
        if ( impares != 0 ){
            cout << "NO SOLUTION\n";
            return 0;
        }

        for (int i = 0; i < 26; i++){
            for (int j = 0; j < charVet[i] / 2; j++){
                cout << (char)('A' + i);
            }
        }

        for (int i = 25; i >= 0; i--){
            for (int j = 0; j < charVet[i] / 2; j++){
                cout << (char)('A' + i);
            }
        }
    }
    else {
        if ( impares > 1 ){
            cout << "NO SOLUTION\n";
            return 0;
        }

        for (int i = 0; i < 26; i++){
            for (int j = 0; j < charVet[i] / 2; j++){
                if ( charVet[i] % 2 == 0 ) cout << (char)('A' + i);
            }
        }


        for (int i = 0; i < charVet[imparIndex]; i++){
            cout << (char)('A' + imparIndex);
        }

        for (int i = 25; i >= 0; i--){
            for (int j = 0; j < charVet[i] / 2; j++){
                if ( charVet[i] % 2 == 0 ) cout << (char)('A' + i);
            }
        }
    }

    cout << "\n";
}