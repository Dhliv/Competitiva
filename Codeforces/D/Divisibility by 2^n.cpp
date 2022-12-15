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

  const int MAX = 200005;
  vector<int> pre(MAX);
  int cnt = 0, aux;
  for(int i = 2; i < MAX; i += 2){
    cnt = 0; aux = i;
    while(aux%2 == 0){
      cnt++;
      aux /= 2;
    }

    pre[i] = cnt;
  }

  int t; cin >> t;
  int n, ans, x;

  while(t--){
    cin >> n;
    ans = 0;

    FOR(i, 0, n){
      cin >> x;

      while(x % 2 == 0){
        ans++;
        x /= 2;
      }
    }

    if(ans >= n) cout << "0\n";
    else{
      vector<int> p;
      for(int i = 2; i <= n; i += 2){
        p.PB(pre[i]);
      }

      sort(p.begin(), p.end());

      cnt = 0;
      FORI(i, p.size() - 1, 0){
        cnt++;
        ans += p[i];
        if(ans >= n) break;
      }

      if(ans >= n) cout << cnt << "\n";
      else cout << "-1\n";
    }
  }

  return 0;
}