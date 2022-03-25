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

  ifstream cin("notlast.in");
  ofstream cout("notlast.out");

  vector<string> cows = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
  map<string, int> acum;
  FOR(i, 0, cows.size()) acum.insert(MP(cows[i], 0));

  int n; cin >> n;
  string cow;
  int quant;

  FOR(i, 0, n){
    cin >> cow >> quant;
    acum[cow] += quant;
  }

  vector<pair<int, string> > neoCows;
  for(auto c: acum) {
    neoCows.PB(MP(c.s, c.f));
  }

  sort(neoCows.begin(), neoCows.end());
  int mini = neoCows[0].f, nxtMini;
  bool able = false;
  FOR(i, 1, neoCows.size()){
    if(mini != neoCows[i].f){
      able = true;
      nxtMini = neoCows[i].f;
      break;
    }
  }

  if(!able) cout << "Tie\n";
  else{
    int cnt = 0;
    FOR(i, 0, neoCows.size()){
      if(neoCows[i].f == nxtMini) cnt++;
    }

    if(cnt != 1) cout << "Tie\n";
    else{
      FOR(i, 0, neoCows.size()) if(neoCows[i].f == nxtMini) cout << neoCows[i].s << "\n";
    }
  }

  return 0;
}
