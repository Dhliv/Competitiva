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
  
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n, x, id, l, r, na, nr;
  string s;
  cin >> t;

  FOR(ab, 0, t){
    cin >> n;
    vector<int> p(n);
    FOR(i, 0, n) cin >> p[i];

    cin >> s;
    deque<int> pa, pr;

    FOR(i, 0, n){
      if(s[i] == 'R') pr.PB(p[i]);
      else pa.PB(p[i]);
    }

    sort(pa.begin(), pa.end());
    sort(pr.begin(), pr.end());

    id = 1;
    l = r = 0;
    na = pa.size();
    nr = pr.size();

    while(l < na){
      if(pa[l] >= id) id++;
      l++;
    }

    while(r < nr){
      if(pr[r] <= id) id++;
      r++;
    }

    if(id == n + 1) cout << "YES\n";
    else cout << "NO\n";
  }
  
  return 0;
}