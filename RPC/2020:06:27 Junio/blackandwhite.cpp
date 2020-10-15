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
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main() {
  int n, W, B, cont = 0, na;
  bool tree = true;
  
  cin >> n;
  na = n;
  vector<string> v(n);

  while(na--){
    cin >> v[cont++];
  }
  //filas:
  
  FOR(i, 0, n){
    W = 0;
    B = 0;
    FOR(j, 0, n){
      if(v[i][j] == 'W') W++;
      else B++;
    }
    if(W != B) tree = false;
  }

  FOR(i, 0, n){
    for(int j = 0; j < (n - 2); j++){
      if(v[i][j] == v[i][j+1] and v[i][j+2] == v[i][j+1]){ tree = false;}
    }
  }
  
  //columnas

  FOR(i, 0, n){
    W = 0;
    B = 0;
    FOR(j, 0, n){
      if(v[j][i] == 'W') W++;
      else B++;
    }
    if(W != B) tree = false;
  }

  FOR(i, 0, n){
    for(int j = 0; j < (n - 2); j++){
      if(v[j][i] == v[j+1][i] and v[j+2][i] == v[j+1][i]){ tree = false;}
    }
  }

  if(tree) cout << 1 << "\n";
  else cout << 0 << "\n";
  
  return 0;
}