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
  int n, dif = 0;
  ll res = 0;
  cin >> n;
  vector<int> v(n);
  map<int, int> m;
  set<int> used;
  
  FOR(i, 0, n){
    cin >> v[i];
    if(m.find(v[i]) == m.end()) m.insert(MP(v[i], 1));
    else m[v[i]]++;
  }
  
  dif = m.size();
  
  FOR(i, 0, n){
    if(used.find(v[i]) == used.end()){
      res += dif;
      if(m[v[i]] == 1) res--;
      used.insert(v[i]);
    }
    m[v[i]]--;
    if(!m[v[i]]) dif--;
  }
  cout << res << "\n";

  return 0;
}