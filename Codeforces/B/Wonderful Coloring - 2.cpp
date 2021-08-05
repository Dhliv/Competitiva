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

bool ch(int &l, int &k, vector<pair<int, int> > &p, vector<int> &ele){
  vector<int> cnt(k + 1, l);
  deque<int> u;
  FOR(i, 1, k + 1) u.PB(i);
  int x = 0, b = -1, ps = 0, gr = k;

  FOR(i, 0, p.size()){
    if(u.empty()) ele[p[i].s] = 0;
    else{
      if(b != p[i].f){
        x = 1;
        b = p[i].f;
        ele[p[i].s] = u[ps];
        cnt[u[ps]]--;
        if(cnt[u[ps]] == 0){
          u.P_F();
          gr--;
          x--;
        } else ps = (ps + 1)%u.size();
      } else{
        if(x < gr){
          x++;
          ele[p[i].s] = u[ps];
          cnt[u[ps]]--;
          if(cnt[u[ps]] == 0){
            u.P_F();
            x--;
            gr--;
          } else ps = (ps + 1)%u.size();
        } else ele[p[i].s] = 0;
      }
    }
  }

  return u.empty();
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n, k, l, h, m;
  cin >> t;

  FOR(ab, 0, t){
    cin >> n >> k;
    vector<int> ele(n);
    vector<pair<int, int> > po(n);

    FOR(i, 0, n){
      cin >> l;
      po[i] = MP(l, i);
    }

    sort(po.begin(), po.end());
    l = 1, h = n/k;

    while(l <= h){
      m = (l + h)/2;
      if(ch(m, k, po, ele)) l = m + 1;
      else h = m - 1;
    }

    ch(h, k, po, ele);

    FOR(i, 0, n) cout << ele[i] << " ";
    cout << "\n";
  }

  return 0;
}
