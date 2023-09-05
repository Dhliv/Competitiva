#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_mini
#define ll long long
#define ull unsigned long long
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

struct edge{
  ll p, val, s;

  edge(){}

  void operator()(ll p, ll val){
    this->p = p;
    this->val = val;
    s = 1;
  }
};

edge &find(ll x, vector<edge> &edges){
  if(x == edges[x].p) return edges[x];
  edge &e = find(edges[x].p, edges);
  edges[x].p = e.p;
  edges[x].val += e.val;
  return edges[x];
}

void merge(ll a, ll b, ll d, vector<edge> &edges){
  if(edges[a].s > edges[b].s){
    swap(a, b);
    d *= -1;
  }

  edges[a].p = b;
  edges[a].val = d;
  edges[b].s += edges[a].s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int n, a, b, d, q;
  edge fa, fb;

  while(t--){
    cin >> n >> q;
    vector<edge> p(n + 1);
    FOR(i, 1, n + 1) p[i](i, 0);

    bool able = true;

    FOR(i, 0, q){
      cin >> a >> b >> d;

      fa = find(a, p);
      fb = find(b, p);
      if(fa.p == fb.p){
        if(p[a].val - p[b].val != d) able = false;
        continue;
      }

      merge(fa.p, fb.p, d - p[a].val + p[b].val, p);
    }

    cout << (able ? "YES" : "NO") << "\n";
  }
 
  return 0;
}