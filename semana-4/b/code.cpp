#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define time first
#define milk second

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n;
    cin >> n;

    map<ll, multiset<ll>> schedule;

    for (int i = 0; i< n; i++){
        ll milk, time;
        cin >> milk >> time;
        schedule[time].insert(milk);
    }


    ll time = 0;
    multiset<ll> result;
    for (auto &par : schedule){

        ll diff = par.time - time;
        
        if ( par.milk.size() > 1 ) {

            ll novoElem = *(--par.milk.end());
            par.milk.erase(--par.milk.end());

            while ( !par.milk.empty() && result.size() < par.time-1 ){
                result.insert(*(--par.milk.end()));
                par.milk.erase(--par.milk.end());
            }

            ll i = 0;
            ll minValueResult = 0;
            ll maxTempoAtual = 0; 

            if ( !result.empty() ) minValueResult = *(result.begin());
            if ( !par.milk.empty() ) maxTempoAtual = *(--par.milk.end());

            while ( maxTempoAtual > minValueResult && i < par.time-1 ){
                result.insert(maxTempoAtual);
                par.milk.erase(--par.milk.end());

                if ( result.size() > 1 ) result.erase(result.begin());
                
                if ( !par.milk.empty() ){
                    maxTempoAtual = *(--par.milk.end());
                }
                else {
                    maxTempoAtual = 0;
                }

                if ( !result.empty() ){
                    minValueResult = *(result.begin());
                }
                else {
                    minValueResult = 0;
                }

                i++;
            }

            result.insert(novoElem);

            time += diff - 1;
        }
        else {
            result.insert(*(--par.milk.end()));
        }

        time++;
    }

    ll total = 0;  
    for (auto i : result){
        total += i;
    }

    cout << total << '\n';
}