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
  bool able;
  vector<string> s(n), ns(n);

  FOR(i, 0, n) cin >> s[i];
  FOR(i, 0, n) cin >> ns[i];

  FOR(i, 0, m){
    vector<bool> hash(26);
    able = true;

    FOR(j, 0, n) hash[s[j][i] - 'A'] = 1;
    FOR(j, 0, n){
      if(hash[ns[j][i] - 'A']){
        able = false;
        break;
      }
    }

    if(able) ans++;
  }

  cout << ans << "\n";

  return 0;
}
