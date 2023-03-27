#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 0;
    cin >> n;

    string s;
    cin >> s;

    string sub = s.substr(n-2, 2);

    if ( sub[sub.length() - 1] == 'i' ) cout << "i" << "\n";
    if ( sub[sub.length() - 1] == 'u' ) cout << "u" << '\n';

    if ( sub.find("is") != sub.npos ) cout << "is" << '\n';
    if ( sub.find("as") != sub.npos ) cout << "as" << '\n';
    if ( sub.find("os") != sub.npos ) cout << "os" << '\n';
    if ( sub.find("us") != sub.npos ) cout << "us" << '\n';
    
    return 0;
}