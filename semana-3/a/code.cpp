#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

map<int, set<int>> restr;
unordered_set<int> repet;
int n;

void printResult(int *result){
    for (int i = 0; i < n ; i++) {
        cout << result[i];
        
        if (i != n-1) cout << " ";
    }
    
    cout << endl;
}

bool podePor(int j){
    set<int> antesJ = restr[j];

    for (auto li : antesJ) 
        if ( repet.find(li) != repet.end() ) return false;
    
    return true;
}

void backt(int i, int *result){
    if (i == n) {
        printResult(result);
        return;
    }

    for (int j = 1 ; j <= n; j++){
        if ( repet.find(j) == repet.end() ){
            if ( podePor(j) ){
                result[i] = j;
                repet.insert(j);
                backt(i + 1, result);
                repet.erase(j);
                result[i] = 0;
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int c;
    cin >> n >> c;

    int result[n];

    for (int i = 0; i < c; i++) { 
        int x, y; 
        cin >> x >> y; 
        restr[x].insert(y);
    }

    backt(0, result);
}