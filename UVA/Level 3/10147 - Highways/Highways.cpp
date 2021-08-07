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

bool comp(pair<int, pair<int, int> > &a, pair<int, pair<int, int> > &b){
  return a.f < b.f;
}

int find(int x, vector<int> &p){
  if(p[x] == x) return x;
  return p[x] = find(p[x], p);
}

void com(int &a, int &b, vector<int> &p, vector<int> &s){
  if(s[a] < s[b]) swap(a, b);

  p[b] = a;
  s[a] += s[b];
  return;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n, x, y, c, xf, yf, m;
  cin >> t;

  FOR(ab, 0, t){
    if(ab) cout << "\n";
    cin >> n;
    vector<int> s(n + 1, 1), p(n + 1);
    vector<pair<int, int> > pt(n + 1);
    FOR(i, 1, n + 1) p[i] = i;

    FOR(i, 1, n + 1){
      cin >> x >> y;
      pt[i] = MP(x, y);
    }

    cin >> m;
    FOR(i, 0, m){
      cin >> x >> y;
      xf = find(x, p);
      yf = find(y, p);

      if(xf != yf) com(xf, yf, p, s);
    }

    deque<pair<int, pair<int, int> > > q;

    FOR(i, 1, n){
      FOR(j, i + 1, n + 1){
        x = pt[i].f - pt[j].f;
        y = pt[i].s - pt[j].s;
        x *= x;
        y *= y;
        q.PB(MP(x + y, MP(i, j)));
      }
    }

    sort(q.begin(), q.end(), comp);

    deque<pair<int, int> > ans;

    FOR(i, 0, q.size()){
      x = q[i].s.f;
      y = q[i].s.s;
      xf = find(x, p);
      yf = find(y, p);

      if(xf != yf){
        ans.PB(MP(x, y));
        com(xf, yf, p, s);
      }
    }

    if(ans.empty()) cout << "No new highways need\n";
    else FOR(i, 0, ans.size()) cout << ans[i].f << " " << ans[i].s << "\n";
  }

  return 0;
}
