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

int main(){
  int mini, n, m, d, des, aux;
  bool poss;
  string a, b;
  
  while(cin >> a >> b){
    n = a.size(), m = b.size();
    mini = n + m;
    poss = false;
    vector<int> un(n), dos(m);
    
    FOR(i, 0, n) un[i] = a[i] - '0';
    FOR(i, 0, m) dos[i] = b[i] - '0';
    
    FOR(i, 0, n - m + 1){
      FOR(j, i, m + i){
        if(un[j] + dos[j - i] > 3) break;
        if(j + 1 == m + i) poss = true;
      }
      if(poss) break;
    }
    
    if(poss) cout << n << "\n";
    else{
      FOR(i, 1, m){
        d = min(n, m - (int)i);
        FOR(j, 0, d){
          if(un[j] + dos[j + i] > 3) break;
          if(j + 1 == d){
            poss = true;
            mini = n + i;
            if(m > n and (m - n - i) > 0) mini += (m - n - i);
            break;
          }
        }
        if(poss) break;
      }
      
      poss = false;
      d = max(0, m - n);
      FOR(i, d, m){
        des = max(i - d, n - m + i);
        FOR(j, des, n){
          if(un[j] + dos[j - des] > 3) break;
          if(j + 1 == n){
            poss = true;
            mini = min(mini, n + int(i));
            break;
          }
        }
        if(poss) break;
      }
      
      cout << mini << "\n";
    }
  }
  
  return 0;
}