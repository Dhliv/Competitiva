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

struct apis{
  ll a, p, i, s;

  apis(ll a, ll p, ll i, ll s){
    this->a = a;
    this->p = p;
    this->i = i;
    this->s = s;
  }

  apis(){}

  void create(ll a, ll p, ll i, ll s){
    this->a = a;
    this->p = p;
    this->i = i;
    this->s = s;
  }

  ll maxi(){
    return p;
  }
};

apis neutro(0, 0, 0, 0);

apis comapis(apis l, apis r){
  ll t = l.a + r.a;
  apis res(t, max(l.p, l.a + r.p), max(l.i, max(r.i, max(t, l.s + r.p))), max(r.s, l.s + r.a));
  return res;
}

struct st{
  int l, r, m;
  apis info;
  st *left, *right;

  void com(){
    info = comapis(left->info, right->info);
  }

  st(int l, int r, vector<int> &p){
    this->l = l;
    this->r = r;

    if(l == r) info.create(p[l], p[l], p[l], p[l]);
    else{
      m = (l + r)/2;
      left = new st(l, m , p);
      right = new st(m + 1, r, p);
      com();
    }
  }

  void up(int &i, int &v){
    if(l == r) info.create(v, v, v, v);
    else{
      if(i <= m) left->up(i, v);
      else right->up(i, v);
      com();
    }
  }

  apis get(int &i, int &j){
    if(r < i or l > j) return neutro;
    if(i <= l and r <= j) return info;
    return comapis(left->get(i, j), right->get(i, j));
  }
};

ll maxi(ll a, ll b){
  return (a > b ? a : b);
}
  
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, q, t, x, y;
  cin >> n >> q;
  vector<int> p(n + 1);
  FOR(i, 1, n + 1) cin >> p[i];

  st tr(1, n, p);

  FOR(i, 0, q){
    cin >> t >> x >> y;

    if(t == 2) cout << maxi(tr.get(x, y).maxi(), 0) << "\n";
    else tr.up(x, y);
  }
  
  return 0;
}