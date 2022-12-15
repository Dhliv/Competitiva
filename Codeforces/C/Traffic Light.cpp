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
#define PI 3.14159265358979323846

using namespace std;

const ld EPSILON = 0.0000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int n;
  char k;
  int aux;

  while(t--){
    cin >> n >> k;
    string s; cin >> s;

    if(k == 'g'){
      cout << "0\n";
      continue;
    }

    vector<vector<int> > pos(256);
    FOR(i, 0, s.size()){
      pos[s[i]].PB(i);
    }

    pos['g'].PB(INF);
    int ans = 0;
    FOR(i, 0, pos[k].size()){
      aux = pos['g'][upper_bound(pos['g'].begin(), pos['g'].end(), pos[k][i]) - pos['g'].begin()];
      if(aux == INF) aux = pos['g'][0];

      aux = (aux - pos[k][i] + s.size())%s.size();
      ans = max(ans, aux);
    }

    cout << ans << "\n";
  }

  return 0;
}