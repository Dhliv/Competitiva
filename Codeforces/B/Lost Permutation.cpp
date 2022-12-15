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

  int t; cin >> t;
  int m, s, sum, x, l, r;

  while(t--){
    cin >> m >> s;
    vector<int> hash(101);
    sum = 0;
    l = INF;
    r = 0;

    FOR(i, 0, m){
      cin >> x;
      hash[x] = 1;
      l = min(l, x);
      r = max(r, x);
    }

    FOR(i, 1, l){
      hash[i] = 1;
      sum += i;
    }

    FOR(i, l, r){
      if(hash[i]) continue;
      sum += i;
      hash[i] = 1;
    }

    if(sum > s) cout << "NO\n";
    else if(sum == s) cout << "YES\n";
    else{
      bool able = true;
      FOR(i, r + 1, 1001){
        if(sum + i > s){
          able = false;
          break;
        }

        sum += i;
        if(sum == s) break;
      }

      if(able) cout << "YES\n";
      else cout << "NO\n";
    }
  }

  return 0;
}