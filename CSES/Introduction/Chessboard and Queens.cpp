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

set<set<pair<int, int> > > poss;
set<pair<int, int> > act;

bool check(pair<int, int> a, pair<int, int> b) {
  if(a.f == b.f or a.s == b.s) return true;
  if((a.f - b.f) == (a.s - b.s)) return true;
  if((a.f - b.f) == -(a.s - b.s)) return true;
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<string> d(8);
  vector<int> p(8);
  FOR(i, 0, 8) cin >> d[i];
  FOR(i, 1, 8) p[i] = i;

  int ans = 0;
  bool able;
  do{
    able = true;
    FOR(i, 0, 7){
      FOR(j, i + 1, 8){
        if(d[i][p[i]] == '*' or d[j][p[j]] == '*' or check(MP(i, p[i]), MP(j, p[j]))){
          able = false;
          break;
        }
      }
    }

    if(able) ans++;
  }while(next_permutation(p.begin(), p.end()));

  cout << ans << "\n";

  return 0;
}
