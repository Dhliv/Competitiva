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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin("whereami.in");
  ofstream cout("whereami.out");

  int n; cin >> n;
  string s, ns; cin >> s;

  bool able;
  FOR(i, 1, n){
    set<string> p;
    able = 1;

    FOR(j, 0, n - i + 1){
      ns = "";
      FOR(k, 0, i){
        ns.PB(s[j + k]);
      }

      if(p.count(ns)){
        able = 0;
        break;
      }

      p.insert(ns);
    }

    if(able){
      cout << i << "\n";
      return 0;
    }
  }

  cout << n << "\n";

  return 0;
}
