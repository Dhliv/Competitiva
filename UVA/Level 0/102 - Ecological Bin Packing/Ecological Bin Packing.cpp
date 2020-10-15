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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int b;
  ll cost, aux1, aux2;
  string pro;
  vector<char> letras{'B', 'G', 'C'};
  
  while(cin >> b){
    vector<vector<int> > data(3, vector<int> (3));
    data[0][0] = b;
    
    FOR(i, 1, 9) cin >> data[i/3][i%3];
    vector<pair<ll, string> > ans;
    
    pro = "HHH";
    FOR(i, 0, 3){
      cost = 0;
      pro[0] = letras[i];
      FOR(j, 0, 3){
        if(i == j) continue;
        cost += data[0][j];
      }
      
      FOR(j, 0, 3){
        aux1 = 0;
        if(j == i) continue;
        pro[1] = letras[j];
        
        FOR(k, 0, 3){
          if(k == j) continue;
          aux1 += data[1][k];
        }
        
        FOR(k, 0, 3){
          aux2 = 0;
          if(k == j or k == i) continue;
          pro[2] = letras[k];
          
          FOR(l, 0, 3){
            if(l == k) continue;
            aux2 += data[2][l];
          }
          
          ans.PB(MP(cost + aux1 + aux2, pro));
        }
      }
    }
    
    sort(ans.begin(), ans.end());
    
    cout << ans[0].s + " " << ans[0].f << "\n";
  }
  
  return 0;
}