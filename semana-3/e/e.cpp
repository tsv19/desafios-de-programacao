#include <bits/stdc++.h>
using namespace std;

set<int> s;

int iii(int a, int b, int c){
    return (a*b+c);
}

int uuu(int d, int e, int f){
    return (f+e)*d;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    while (n--){
        int a;
        cin >> a;
        s.insert(a);
    }
    

    map<int, int> m;
    for (auto a: s)
        for (auto b: s)
            for (auto c: s)
                m[iii(a,b,c)]++;

    int r = 0;

    for (auto d: s){
        if (d == 0) continue;

        for (auto e: s)
            for (auto f: s){
                int val = uuu(d,e,f);
                if ( m.count(val) == 1 ){
                    r+= m[val];
                };
            }
    }

    cout << r << '\n';
}
