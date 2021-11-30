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

  int n, s, k, x; cin >> n >> s >> k;
  vector<int> p(k);

  FOR(i, 0, k){
    cin >> p[i];
  }

  sort(p.begin(), p.end());

  deque<int> q(n, 0);
  int tam = s, l = 0, maxi = 0;

  FOR(i, 0, k){
    while(p[i] > tam){
      l++;
      tam += s;
    }
    q[l]++;
    maxi = max(maxi, q[l]);
  }

  FORI(i, maxi, 1){
    FOR(j, 0, n){
      cout << (q[j] >= i ? '#' : '.');
    }
    cout << "\n";
  }

  FOR(i, 0, n) cout << "-";
  cout << "\n";
  
  return 0;
}