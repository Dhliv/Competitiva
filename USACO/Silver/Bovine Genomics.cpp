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

  ifstream cin;
  cin.open("cownomics.in");
  ofstream cout("cownomics.out");

  int n, m, ans = 0; cin >> n >> m;
  vector<string> s(n), ns(n);
  string a, b;
  bool able;

  FOR(i, 0, n) cin >> s[i];
  FOR(i, 0, n) cin >> ns[i];

  FOR(i, 0, m - 2){
    FOR(j, i + 1, m - 1){
      FOR(k, j + 1, m){
        able = true;
        unordered_set<string> words;
        FOR(l, 0, n){
          a = "";
          a.PB(s[l][i]); a.PB(s[l][j]); a.PB(s[l][k]);
          words.insert(a);
        }

        FOR(l, 0, n){
          b = "";
          b.PB(ns[l][i]); b.PB(ns[l][j]); b.PB(ns[l][k]);
          if(words.count(b)){
            able = false;
            break;
          }
        }

        if(able) ans++;
      }
    }
  }

  cout << ans << "\n";

  return 0;
}
