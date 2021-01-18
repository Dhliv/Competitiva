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

using namespace std;

int find(int x, vector<int> &p){
  if(p[x] == x) return x;
  return p[x] = find(p[x], p);
}

int main(){
  int n, m, x, a, fa, k, dad;
  
  while(cin >> n >> m, n){
    vector<int> p(n), sum(n, 1);
    FOR(i, 0, n) p[i] = i;
    
    FOR(i, 0, m){
      cin >> k;
      if(k){
        cin >> x;
        dad = find(x, p);
        
        FOR(j, 1, k){
          cin >> a;
          fa = find(a, p);
          if(dad != fa){
            p[fa] = dad;
            sum[dad] += sum[fa];
          }
        }
      }
    }
    
    cout << sum[find(0, p)] << "\n";
  }
  
  return 0;
}