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
#define tri pair<int, pair<int, int> > // ab, ce, cp

using namespace std;

string ent;

struct st{
  int l, r, m, mini;
  tri data;
  st *left, *right;

  tri com(tri a, tri b){
    mini = min(a.f, b.s.f);
    return MP(a.f + b.f - mini, MP(a.s.f + b.s.f - mini, a.s.s + b.s.s + mini));
  }

  st(int l, int r){
    this->l = l;
    this->r = r;

    if(l == r){
      if(ent[l - 1] == '(') data = MP(1, MP(0, 0));
      else data = MP(0, MP(1, 0));
    }
    else{
      m = (l + r)/2;
      left = new st(l, m);
      right = new st(m + 1, r);
      data = com(left->data, right->data);
    }
  }

  tri get(int &i, int &j){
    if(i > r or j < l) return MP(0, MP(0, 0));
    if(i <= l and r <= j) return data;
    return com(left->get(i, j), right->get(i, j));
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  int m, x, y;
  cin >> ent >> m;

  st tr(1, ent.size());

  FOR(i, 0, m){
    cin >> x >> y;
    cout << tr.get(x, y).s.s * 2 << "\n";
  }

  return 0;
}