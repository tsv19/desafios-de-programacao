#include <bits/stdc++.h>
using namespace std;

#define cord pair<ll,ll>
using ll = long long;

ll swaps = 0;
ll h;
vector<cord> a;
void merge_sort(int l, int r){
    if (r - l == 1) { return; }
    int mi = l + (r - l) / 2;
    
    merge_sort(l, mi);
    merge_sort(mi, r);
    
    vector<cord> aux(r - l);
    int i = l, j = mi;
    for (int k = 0; k < r - l; k++){
        if (i < mi && j < r){
            if (!(a[i].first < a[j].first)){
                if (a[j].second > h - 1){ swaps += mi - i; }
            }
            if (a[i].first < a[j].first){
                aux[k] = a[i++];
            }
            else {
                aux[k] = a[j++];
            }
        }
        else if (i < mi) {
            aux[k] = a[i++];
        }
        else {
            aux[k] = a[j++];
        }
    }
    copy(aux.begin(), aux.end(), a.begin() + l);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n;
    cin >> n >> h;
    a = vector<cord>(n);

    for (ll i = 0; i < n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }
    merge_sort(0, n);

    cout << swaps << "\n";
}