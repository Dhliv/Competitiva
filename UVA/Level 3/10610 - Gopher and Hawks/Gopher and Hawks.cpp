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

pair<ld, ld> getpt(string &a){
  deque<ld> p;
  string s = "";

  FOR(i, 0, a.size()){
    if(isspace(a[i])){
      p.PB(stold(s));
      s = "";
      i++;
    }
    s.PB(a[i]);
  }

  return MP(p[0], p[1]);
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, a, inii = 0, desti = 1;
  ld x, y, l, u = 1.0, epsi = 1e-6;
  string s;
  pair<ld, ld> ini, dest, ax;

  while(cin >> n >> m, n + m){
    cin >> ini.f >> ini.s;
    cin >> dest.f >> dest.s;
    deque<pair<ld, ld> > p;
    p.PB(ini); p.PB(dest);

    getline(cin, s);
    while(getline(cin, s)){
      if(s.empty()) break;
      s.PB(' ');
      p.PB(getpt(s));
    }

    l = (60.0*n)*(u*m);
    l *= l;

    vector<vector<int> > g(p.size());
    vector<int> sn(p.size(), INF);

    FOR(i, 0, p.size()){
      FOR(j, 0, p.size()){
        x = p[i].f - p[j].f;
        y = p[i].s - p[j].s;
        x *= x;
        y *= y;

        if(fabs(x + y - l) < epsi or x + y < l){
          g[i].PB(j);
          g[j].PB(i);
        }
      }
    }

    sn[inii] = 0;
    deque<int> q;
    q.PB(inii);

    while(!q.empty()){
      a = q.F();
      q.P_F();

      for(int b: g[a]){
        if(sn[b] == INF){
          sn[b] = sn[a] + 1;
          q.PB(b);
        }
      }
    }

    if(sn[desti] == INF) cout << "No.\n";
    else cout << "Yes, visiting " << sn[desti] - 1 << " other holes.\n";
  }
  
  return 0;
}
