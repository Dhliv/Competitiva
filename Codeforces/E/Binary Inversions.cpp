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

const ld EPSILON = 0.0000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int n;
  ll maxi, x, cur;

  while(t--){
    cin >> n;
    vector<int> p(n), p1(n + 1), p2(n + 2);
    FOR(i, 0, n){
      cin >> x;
      p[i] = x;
      if(x) p1[i + 1]++;
      p1[i + 1] += p1[i];
    }

    maxi = 0;
    FORI(i, n - 1, 0){
      if(p[i] == 0) p2[i]++;
      p2[i] += p2[i + 1];
      if(p[i]) maxi += p2[i];
    }

    cur = maxi;
    FOR(i, 0, n){
      if(p[i]) maxi = max(maxi, cur - p2[i + 1] + p1[i]);
      else maxi = max(maxi, cur - p1[i] + p2[i + 1]);
    }

    cout << maxi << "\n";
  }
 
  return 0;
}