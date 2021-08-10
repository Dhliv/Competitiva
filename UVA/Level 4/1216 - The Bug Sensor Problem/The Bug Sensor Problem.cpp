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

ll g, x, y, n, c;
int xf, yf;

bool comp(pair<ll, pair<int, int> > &a, pair<ll, pair<int, int> > &b){
  return a.f < b.f;
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

int look(ll &lim, deque<pair<ll, pair<int, int> > > &q){
  int l = 0, h = q.size() - 1, m;

  while(l <= h){
    m = (l + h)/2;
    if(q[m].f <= lim) l = m + 1;
    else h = m - 1;
  }

  return l;
}

bool ch(ll &lim, vector<int> &p, vector<int> &s, deque<pair<ll, pair<int, int> > > &q){
  int ga = n, m = look(lim, q);

  FOR(i, 0, m){
    x = q[i].s.f;
    y = q[i].s.s;
    xf = find(x, p);
    yf = find(y, p);

    if(yf != xf){
      com(xf, yf, p, s);
      ga--;
    }
  }

  return ga <= g;
}

void rb(vector<int> &p, vector<int> &s){
  FOR(i, 0, n){
    s[i] = 1;
    p[i] = i;
  }
  return;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t, ans;
  ll l, h, m;
  cin >> t;

  FOR(ab, 0, t){
    cin >> g;

    deque<pair<int, int> > pt;
    while(cin >> x, x != -1){
      cin >> y;
      pt.PB(MP(x, y));
    }

    n = pt.size();
    vector<int> p(n), s(n, 1);
    FOR(i, 1, n) p[i] = i;

    h = 0;
    deque<pair<ll, pair<int, int> > > q;
    FOR(i, 0, n){
      FOR(j, i + 1, n){
        x = pt[i].f - pt[j].f;
        y = pt[i].s - pt[j].s;
        x *= x;
        y *= y;
        h = max(h, x + y);
        q.PB(MP(x + y, MP(i, j)));
      }
    }

    sort(q.begin(), q.end(), comp);

    l = 0;
    while(l <= h){
      m = (l + h)/2;
      if(ch(m, p, s, q)) h = m - 1;
      else l = m + 1;
      rb(p, s);
    }

    x = sqrt(l);
    if(x*x != l) x++;
    cout << x << "\n";
  }
  
  return 0;
}
