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

const ld EPSILON = 0.0000000001;

void add(pair<int, int> a, map<pair<int, int>, int> &m){
  auto it = m.find(a);
  if(it != m.end()) it->s++;
  else m.insert(MP(a, 1));
}

void del(pair<int, int> a, map<pair<int, int>, int> &m){
  auto it = m.find(a);
  it->s--;
  if(it->s == 0) m.erase(a);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int q; cin >> q;
  map<pair<int, int>, int> lf, rg;
  char k;
  int l, r;
  FOR(i, 0, q){
    cin >> k >> l >> r;
    if(k == '+'){
      add(MP(r, l), lf);
      add(MP(l, r), rg);
    }else {
      del(MP(r, l), lf);
      del(MP(l, r), rg);
    }

    if(lf.size() <= 1){
      cout << "NO\n";
      continue;
    }

    auto mend = rg.end();
    --mend;

    auto it = lf.begin();
    if(it->f.f >= mend->f.f) cout << "NO\n";
    else cout << "YES\n";
  }

  return 0;
}