#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0;
    cin >> n;

    string s;
    cin >> s;

    int ini = s.find("AAAAAAA");    
    int fim = s.rfind("AAAAAAA");


    if ( ini != -1 && fim != -1 ) {
        cout << fim + 7 - ini << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}

// input
// 75
// GAGAUUGCUAGCAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAGCAUAUGACUAAAAAAAAAAAAAAAAAAAAAAA
// output
// 63

// input
// 75
// GAGCAGAUUAAUAAAAAAAAAAAAAAAAAAAAAAAUGCAUCCCCCCCCCCCCCCCCCAAAGGCUGCACCAGAAUU
// GAGCAGAUUAAU AAAAAAA AAAAAAA AAAAAAAAA UGCAUCCCCCCCCCCCCCCCCCAAAGGCUGCACCAGAAUU
// output
// 23

// input
// 60
// AUGGAUUCUAACACUGUGUCAAGUUUUCAGGUAGAUUGCUUCCUUUGGCAUGUCCGAAAA
// output
// 0