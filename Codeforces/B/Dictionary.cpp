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
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  int t, index, n = 1;
  map<string, int> p;
  string s, aux;
 
  FOR(i, 0, 26) {
    s = "";
    s.PB('a' + i);
    FOR(j, 0, 26) {
      if(i == j) continue;
      aux = s;
      aux.PB('a' + j);
 
      p.insert(MP(aux, n++));
    }
  }
 
  cin >> t;
  FOR(i, 0, t){
    cin >> s;
    index = p.find(s)->s;
 
    cout << index << "\n";
  }
  
  return 0;
}