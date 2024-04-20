#include <bits/stdc++.h>

using namespace std;

using ll = int ;

double EPS = 1e-4;

ll n;
ll a;

double calcula_area(double altura, vector<ll> v){
    double soma = 0.0;
    
    for (ll i = n - 1; i >= 0; --i){
        if ( altura >= (double)v[i] ) return soma;

        soma += (double)v[i] - altura;
    }

    return soma;
}

double binary_search(vector<ll> v){
    double start = 0.0;
    double end = (double)v[n - 1];
    double mid;

    int it = 0;

    while ( start <= end && it < 40 ){
        mid = (start + end) / 2.0;
        
        double area_calculada = calcula_area(mid, v);

        if ( fabs(area_calculada - (double)a) < EPS ){
            return mid;
        }

        if ( area_calculada < (double)a ) end = mid;
        else start = mid;
        
        it++;
    }

    return mid;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    while ( cin >> n >> a && a != 0 && n != 0 ){
        double area = 0.0;

        vector<ll> c(n);
        for (ll i = 0; i < n; i++){
            cin >> c[i];
            area += (double)c[i];
        }

        if ( area == (double)a ){
            cout << ":D" << endl;
        } 
        else if ( area < (double)a ){
            cout << "-.-" << endl;
        }
        else {
            double res = 0.0;

            sort(c.begin(), c.end());
            res = binary_search(c);

            cout << std::fixed << std::setprecision(4) << res << endl;
        }
    }
}