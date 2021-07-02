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
#define MAX 500005

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n, m, h, x;
  cin >> n >> m >> h;
  vector<int> ms(m), ns(n);
  
  FOR(i, 0, m) cin >> ms[i];
  FOR(i, 0, n) cin >> ns[i];
  
  FOR(i, 0, n){
    FOR(j, 0, m){
      cin >> x;
      if(x) cout << min(ns[i], ms[j]);
      else cout << "0";
      if(j + 1 < m) cout << " ";
    }
    cout << "\n";
  }
  
  return 0;
}