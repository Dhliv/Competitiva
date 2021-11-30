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

  int n, l, r;
  ll sum = 0;
  cin >> n;
  vector<int> p(n), ord(n);
  FOR(i, 0, n) cin >> p[i];

  sort(p.begin(), p.end());
  l = 0;
  r = n - 1;

  FOR(i, 0, n){
    if(i & 1){
      ord[r--] = p[i];
    }else{
      ord[l++] = p[i];
    }
  }

  FOR(i, 1, n){
    sum += max(ord[i], ord[i - 1]);
  }
  sum += max(ord[0], ord[n - 1]);

  cout << sum << "\n";
  
  return 0;
}