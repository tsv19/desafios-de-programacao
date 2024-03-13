#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;

    stack<pair<int, string>> s;

    cin >> n;

    for (int i = 0; i < n; i++){
        int a;
        string d;

        cin >> a >> d;

        if ( !s.empty() ){
            if ( a == s.top().first && d == "L" && s.top().second == "L" ){
                break;
            }
            else if ( a > s.top().first ){
                break;
            }
        }
        
        if ( d == "L" ) {
            s.push(make_pair(a, d));
        }

        if ( d == "O" ){
            if ( s.empty() ){
                s.push(make_pair(a, d));
                break;
            }
            else if ( a == s.top().first && s.top().second == "L" ){
                s.pop();
            }
            else {
                s.push(make_pair(a, d));
                break;
            }
        }
    }

    if (s.empty())
        cout << "S\n";
    else
        cout << "N\n";
}
