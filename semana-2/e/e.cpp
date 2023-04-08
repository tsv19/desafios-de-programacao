#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main() {
    uint16_t nTestes = 0;
    cin >> nTestes;

    while (nTestes--){
        ll poste;
        unsigned int formigas;
        cin >> poste >> formigas;

        ll minDistanciaFormiga = 0, maxDistanciaFormiga = 0; 

        while (formigas--){
            ll formiga;
            cin >> formiga;


            ll a = min(formiga, poste - formiga);
            ll b = max(formiga, poste - formiga);
            

            minDistanciaFormiga = max(minDistanciaFormiga, a);
            maxDistanciaFormiga = max(maxDistanciaFormiga, b);
        }
        cout << minDistanciaFormiga << " " << maxDistanciaFormiga << endl;
    }
}