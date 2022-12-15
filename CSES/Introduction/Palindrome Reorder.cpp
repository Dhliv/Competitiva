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
#define PI 3.14159265358979323846

using namespace std;

const ld EPSILON = 0.0000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> hash(256);
  string s, ans, ax; cin >> s;

  FOR(i, 0, s.size()){
    hash[s[i]]++;
  }

  int impares = 0, pos;
  FOR(i, 0, 256) impares += hash[i] & 1;

  if(impares > 1) cout << "NO SOLUTION\n";
  else{
    ans = "";
    char l;

    FOR(i, 0, 256){
      if(hash[i]){
        for(int j = 1; j < hash[i]; j += 2) ans.PB((char) i);
        if(hash[i] & 1) l = (char) i;
      }
    }

    pos = ans.size() - 1;
    if(impares) ans.PB(l);

    FORI(i, pos, 0) ans.PB(ans[i]);
    cout << ans << "\n";
  }

  return 0;
}