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

struct st{
  int l, r, m, vecs;
  char izq, der;
  st *left, *right;

  void com(){
    vecs = left->vecs + right->vecs;
    izq = left->izq;
    der = right->der;
    vecs += (right->izq == left->der ? 1 : 0);
  }

  st(int l, int r, string &p){
    this->l = l;
    this->r = r;

    if(l == r){
      vecs = 0;
      izq = der = p[l];
    }
    else{
      m = (l + r)/2;
      left = new st(l, m, p);
      right = new st(m + 1, r, p);
      com();
    }
  }

  pair<int, pair<char, char> > get(int i, int j){
    if(r < i or l > j) return MP(0, MP('a', 'a'));
    if(i <= l and r <= j) return MP(vecs, MP(izq, der));
    auto a = left->get(i, j);
    auto b = right->get(i, j);
    pair<int, pair<char, char> > ans;

    if(a == MP(0, MP('a', 'a'))) return b;
    if(b == MP(0, MP('a', 'a'))) return a;
    ans.f = a.f + b.f;
    ans.s.f = a.s.f;
    ans.s.s = b.s.s;
    ans.f += (a.s.s == b.s.f ? 1 : 0);

    return ans;
  }
};
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  int n, x, y;
  cin >> s >> n;

  st tr(0, s.size() - 1, s);

  FOR(i, 0, n){
    cin >> x >> y;
    x--;
    y--;
    cout << tr.get(x, y).f << "\n";
  }
 
  return 0;
} 