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

struct info{
  int t, x, y;
};

bool comp(info &a, info &b){
  return a.t < b.t;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("tracing.in");
  ofstream cout("tracing.out");

  int n, T, kmin, kmax, xMax, xMin; cin >> n >> T;
  vector<bool> infect, supposed(n + 1);
  vector<int> handshakes;
  deque<int> ini;
  string s; cin >> s;

  FOR(i, 0, n){
    supposed[i + 1] = s[i] == '1' ? 1 : 0;
    if(supposed[i + 1]) ini.PB(i + 1);
  }

  vector<info> p(T);
  FOR(i, 0, T) cin >> p[i].t >> p[i].x >> p[i].y;

  sort(p.begin(), p.end(), comp);

  kmax = 0;
  kmin = INF;
  bool able;
  set<int> ans;
  while(!ini.empty()){

    FOR(i, 0, T + 1){
      able = true;
      infect.assign(n + 1, 0);
      handshakes.assign(n + 1, 0);
      infect[ini.F()] = 1;

      FOR(j, 0, T){
        if(infect[p[j].x]) handshakes[p[j].x]++;
        if(infect[p[j].y]) handshakes[p[j].y]++;
        if(infect[p[j].x] and handshakes[p[j].x] <= i) infect[p[j].y] = 1;
        if(infect[p[j].y] and handshakes[p[j].y] <= i) infect[p[j].x] = 1;
      }

      FOR(j, 1, n + 1){
        if(infect[j] != supposed[j]){
          able = false;
          break;
        }
      }

      if(able){
        kmax = max(kmax, (int)i);
        kmin = min(kmin, (int)i);
        ans.insert(ini.F());
      }
    }

    ini.P_F();
  }

  cout << ans.size() << " " << kmin << " ";
  if(kmax == T) cout << "Infinity\n";
  else cout << kmax << "\n";

  return 0;
}
