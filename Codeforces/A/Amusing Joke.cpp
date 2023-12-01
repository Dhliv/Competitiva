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

  string a, b, c; cin >> a >> b >> c;
  vector<int> hs(255);

  FOR(i, 0, c.size()) hs[c[i]]++;
  FOR(i, 0, a.size()) hs[a[i]]--;
  FOR(i, 0, b.size()) hs[b[i]]--;

  bool able = true;
  FOR(i, 0, 255){
    if(hs[i]){
      able = false;
      break;
    }
  }

  cout << (able ? "YES" : "NO") << "\n";
  
  return 0;
}