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
  cin.open("badmilk.in");
  ofstream cout("badmilk.out");

  int n, m, d, s, ans = INF; cin >> n >> m >> d >> s;
  vector<vector<int> > tims(n + 1, vector<int> (m + 1, INF));
  map<int, int> consume;

  int p, lm, lt;
  FOR(i, 0, d){
    cin >> p >> lm >> lt;
    tims[p][lm] = min(tims[p][lm], lt);
  }

  FOR(i, 0, s){
    cin >> p >> lt;

    FOR(j, 1, m + 1){
      if(tims[p][j] < lt){
        if(consume.count(j)){
          consume[j]++;
        }else consume.insert(MP(j, 1));
      }
    }
  }

  set<int> possi;
  for(auto ele: consume){
    if(ele.s == s) possi.insert(ele.f);
  }

  int act;
  ans = 0;
  for(auto milk: possi){
    act = 0;
    FOR(i, 1, n + 1) if(tims[i][milk] != INF) act++;

    ans = max(ans, act);
  }

  cout << ans << "\n";

  return 0;
}
