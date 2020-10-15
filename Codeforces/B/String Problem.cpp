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
  string a, b, res;
  char z, w;
  bool able = true;
  ll ans = 0, mini, ax;
  int n, x, y, k;
  cin >> a >> b;
  
  if(a.size() == b.size()){
    cin >> n;
    vector<vector<int> > pesos(26, vector<int> (26, INF)), grafo(26);
    res = a;
    
    FOR(i, 0, n){
      cin >> z >> w >> x;
      if(pesos[z - 'a'][w - 'a'] == INF){
        pesos[z - 'a'][w - 'a'] = x;
        grafo[z - 'a'].PB(w - 'a');
      }else pesos[z - 'a'][w - 'a'] = min(pesos[z - 'a'][w - 'a'], x);
    }
    
    vector<vector<int> > ss(26);
    
    FOR(i, 0, 26){
      priority_queue<pair<int, int> > p;
      p.push(MP(0, i));
      vector<int> seen(26, INF), vistos(26);
      seen[i] = 0;
        
      while(!p.empty()){
        x = p.top().s;
        p.pop();
          
        if(vistos[x]) continue;
        vistos[x] = 1;
          
        FOR(j, 0, grafo[x].size()){
          y = grafo[x][j];
          k = pesos[x][y];
          if(seen[y] > k + seen[x]){
            seen[y] = seen[x] + k;
            p.push(MP(-seen[y], y));
          }
        }
      }
      
      ss[i] = seen;
    }
    
    FOR(i, 0, a.size()){
      if(a[i] != b[i]){
        x = a[i] - 'a';
        y = b[i] - 'a';
        
        mini = INF;
        FOR(j, 0, 26){
          ax = (ll)ss[x][j] + (ll)ss[y][j];
          if(mini > ax){
            mini = ax;
            z = (char)(j + 'a');
          }
        }
        
        if(mini == INF){
          able = false;
          break;
        }else{
          ans += mini;
          res[i] = z;
        }
      }
    }
    
    if(able) cout << ans << "\n" + res + "\n";
    else cout << "-1\n";
  }else cout << "-1\n";
  
  return 0;
}