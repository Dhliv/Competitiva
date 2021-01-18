#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
#define ld long double
#define PB push_back
#define PF push_front
#define P_F pop_front
#define P_B pop_back
#define F front
#define B back
#define f first
#define s second
#define MP make_pair
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define FORI(i, a, b) for(ll i = a; i >= b; i--)
#define tri pair<int, pair<int, int> >

using namespace std;

int main(){
  int n, N, a;
  
  while(cin >> N){
    n = (1 << N);
    vector<vector<int> > grafo(n);
    vector<int> w(n), pw(n);
    priority_queue<int> q;
    
    FOR(i, 0, n) cin >> w[i];
    
    FOR(i, 0, n){
      FOR(j, 0, N){
        a = (i | (1 << j));
        if(a != i){
          grafo[i].PB(a);
          grafo[a].PB(i);
        }
      }
    }
    
    FOR(i, 0, n){
      a = 0;
      FOR(j, 0, grafo[i].size()) a += w[grafo[i][j]];
      
      pw[i] = a;
    }
    
    FOR(i, 0, n){
      a = pw[i];
      FOR(j, 0, grafo[i].size()) a = max(a, pw[i] + pw[grafo[i][j]]);
      
      q.push(a);
    }
    
    cout << q.top() << "\n";
  }
  
  return 0;
}