#include <bits/stdc++.h>
#define INF 1000000000
#define ll long long
#define PB push_back
#define PF push_front
#define P_F pop_front
#define P_B pop_back
#define F front
#define B back
#define MP make_pair
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int cases, n, m, cont;
  string ans;
  bool poss;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> n >> m;
    vector<string> all(n);
    poss = false;
    
    FOR(i, 0, n)
      cin >> all[i];
      
    ans = all[0];
    
    FOR(i, 0, m){
      for(char re = 'a'; re <= 'z'; re++){
        ans[i] = re;
        FOR(j, 1, n){
          cont = 0;
          FOR(k, 0, m){
            if(all[j][k] != ans[k])
              cont++;
          }
          
          if(cont > 1)
            break;
          else if(j+1 == n)
            poss = true;
        }
        if(poss)
          break;
        ans = all[0];
      }
      if(poss)
        break;
    }
    
    if(poss or n == 1)
      cout << ans << "\n";
    else
      cout << "-1\n";
  }
  
  return 0;
}