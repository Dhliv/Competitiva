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

  ifstream cin;
  cin.open("blist.in");
  ofstream cout("blist.out");

  int n; cin >> n;
  vector<int> bkt(n), ini(1001, -1), fin(1001, -1);
  int a, b, x;

  FOR(i, 0, n){
    cin >> a >> b >> x;
    bkt[i] = x;
    ini[a] = i;
    fin[b] = i;
  }

  int ans = 0, act = 0;
  FOR(i, 1, 1001){
    if(ini[i] != -1){
      act += bkt[ini[i]];
      ans = max(ans, act);
    }

    if(fin[i] != -1) act -= bkt[fin[i]];
  }

  cout << ans << "\n";
  
  return 0;
}
