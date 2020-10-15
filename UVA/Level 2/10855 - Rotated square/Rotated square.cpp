#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
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

vector<string> rotate(vector<string> &sq){
  vector<string> n9 = sq;
  int n = sq.size();
  
  FOR(j, 0, n){
    FORI(i, n - 1, 0){
      n9[j][n - (i + 1)] = sq[i][j];
    }
  }
  
  return n9;
}

int main(){
  int n, m;
  string ent;
  bool able;
  
  while(cin >> n >> m, n + m){
    vector<string> big(n), sq(m);
    vector<int> v(4);
    
    FOR(i, 0, n) cin >> big[i];
    FOR(i, 0, m) cin >> sq[i];
    
    FOR(a, 0, 4){
      FOR(i, 0, n - m + 1){
        FOR(j, 0, n - m + 1){
          able = true;
          FOR(x, 0, m){
            FOR(y, 0, m){
              if(sq[x][y] != big[i + x][j + y]){
                able = false;
                x += m;
                break;
              }
            }
          }
          
          if(able) v[a]++;
        }
      }
      sq = rotate(sq);
    }
    
    FOR(i, 0, 3) cout << v[i] << " ";
    cout << v[3] << "\n";
  }
  
  return 0;
}
