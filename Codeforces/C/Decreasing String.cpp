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

struct dt{
  char k;
  int pos;

  dt(){}
  dt(char k, int pos) : k(k), pos(pos) {}
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  string s;
  ll n, p, disp, pos;

  while(t--){
    cin >> s >> pos;
    n = s.size();
    vector<int> del(n);
    deque<dt> q;
    disp = n;
    p = 0;

    while(pos > disp){
      //cout << pos << " > " << disp << ": ";
      pos -= disp;
      disp--;

      //cout << "Added: [";
      while(p < n and (q.empty() or s[p] >= q.F().k)){
        //cout << s[p] << ", ";
        q.PF(dt(s[p], p));
        p++;
      }
      //cout << "] ";    

      //cout << "Deleted: [" << q.F().k << "]\n";
      if(p < n and s[p] < q.F().k){
        del[q.F().pos] = 1;
        q.P_F();
        continue;
      }

      del[q.F().pos] = 1;
      q.P_F();
    }

    pos--;
    string ans = "";
    FOR(i, 0, n){
      if(del[i]) continue;
      ans.PB(s[i]);
    }

    cout << ans[pos];
  }

  cout << "\n";

  return 0;
}