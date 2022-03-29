#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s, t; cin >> s >> t;
  ll p = 0;
  ll ans = 0, last = -1, n = s.size();

  deque<pair<char, ll> > q;
  int ap[256] = {0};

  FOR(i, 0, n){
    if(t[p] == s[i]){
      q.PB(MP(t[p], i));
      ap[t[p]]++;
      p++;
    }else if(ap[s[i]]){
        ap[s[i]]++;
        q.PB(MP(s[i], i));
    }

    while(p == t.size()) {
      deque<pair<char, ll> > nq;

      p--;
      FORI(j, (int)q.size() - 1, 0){
        if(p < 0) ap[q[j].f]--;
        else if(t[p] == q[j].f){
          p--;
          nq.PF(q[j]);
        }else {
          nq.PF(q[j]);
        }
      }

      q.swap(nq);
      ans += (q[0].s - last)*(n - q[(int)q.size() - 1].s);
      last = q.F().s;
      q.P_F();
      p = -1;
    }

    while(p == -1) {
      deque<pair<char, ll> > nq;

      p = 0;
      FOR(j, 0, q.size()){
        if(t[p] == q[j].f){
          p++;
          nq.PB(q[j]);
        }else if(ap[q[j].f]){
            ap[q[j].f]++;
            nq.PB(q[j]);
        }else ap[q[j].f]--;
      }

      q.swap(nq);
    }
  }

  cout << ans << "\n";

  return 0;
}
