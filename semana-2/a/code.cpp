#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

int LIFO = 0b001;
int FIFO = 0b010;
int PRIO = 0b100;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, alg = 0b111;
    
    stack<int> s;
    queue<int> q;
    priority_queue<int> pq;

    cin >> n;

    while (n--){
        int i, e;

        cin >> i >> e;

        if ( !i ){
            s.push(e);
            q.push(e);
            pq.push(e);
        }

        if ( i ){
            int s_v = s.top();
            s.pop();

            int q_v = q.front();
            q.pop();
            
            int pq_v = pq.top();
            pq.pop();

            if ( e != s_v && alg & LIFO){
                alg ^= LIFO;
            }
            
            if ( e != q_v && alg & FIFO){
                alg ^= FIFO;
            }
            
            if ( e != pq_v && alg & PRIO){
                alg ^= PRIO;
            }
        } 
    }

    if ( alg == LIFO ){
        cout << "lifo\n";
    }
    else if ( alg == FIFO ){
        cout << "fifo\n";
    }
    else if ( alg == PRIO ){
        cout << "priority\n";
    }
    else if ( alg == 0b011 || alg == 0b101 || alg == 0b110 || alg == 0b111 ){
        cout << "ambiguous\n";
    } 
    else {
        cout << "unknown\n";
    }
}
