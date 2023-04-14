#include <bits/stdc++.h>
using namespace std;


unordered_set <int> s;
map <int, set<int>> rp;
int n = 0;
int r;

void printSet(int *v){
    for (int i = 0; i < n; i++){
        cout << v[i];
        if (i != n-1) cout << " ";
    }
    cout << "\n";
}

bool checaRestricao(int i){
    set a = rp[i];

    if ( a.size() == 0 ) return true;

    for (auto it = a.begin(); it != a.end(); it++){
        if ( s.find(*it) != s.end()){
            return false;
        }
    }
    return true;
}

void ba(int c, int *v){
    if (c == n){
        printSet(v);
        return;
    }

    for (int i = 1; i <= n; i++){
        // checa repeticao
        if (s.find(i) == s.end()){
            if (checaRestricao(i)){
                v[c] = i;
                s.insert(i);
                ba(c+1, v);
                s.erase(i);
                v[c] = 0;
            }
        }
    }
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> r;
    int v[n];

    while (r--){
        int a, b;
        cin >> a >> b;
        rp[a].insert(b);
    }

    ba(0, v);
}