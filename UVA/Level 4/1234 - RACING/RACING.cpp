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
  return a.f > b.f;
}

int find(int x, vector<int> &p){
  if(x == p[x]) return x;
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

  int t, n, m, x, y, xf, yf, c, ans;
  cin >> t;

  FOR(ab, 0, t){
    cin >> n >> m;
    vector<int> p(n + 1), s(n + 1, 1);
    FOR(i, 1, n + 1) p[i] = i;
    deque<pair<int, pair<int, int> > > q;

    FOR(i, 0, m){
      cin >> x >> y >> c;
      q.PB(MP(c, MP(x, y)));
    }

    sort(q.begin(), q.end(), comp);

    ans = 0;
    FOR(i, 0, m){
      xf = find(q[i].s.f, p);
      yf = find(q[i].s.s, p);

      if(xf != yf) com(xf, yf, p, s);
      else ans += q[i].f;
    }

    cout << ans << "\n";
  }
  cin >> t;
  
  return 0;
}
