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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, x, y, nodo;
  cin >> n >> m;

  vector<bool> s(n + 1);

  FOR(i, 0, m){
    cin >> x >> y;
    s[x] = s[y] = 1;
  }

  FOR(i, 1, n + 1){
    if(s[i] == 0){
      nodo = i;
      break;
    }
  }

  cout << n - 1 << "\n";
  FOR(i, 1, n + 1){
    if(nodo == i) continue;
    cout << nodo << " " << i << "\n";
  }

  return 0;
}