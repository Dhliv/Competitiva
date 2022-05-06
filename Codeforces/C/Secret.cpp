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

  int n, k; cin >> n >> k;
  vector<int> pos(n + 1), corres(k + 1, n/k);

  if((n/k) < 3) cout << "-1\n";
  else{
    FOR(i, 1, 1 + n%k) corres[i]++;
    int cnt;

    FOR(i, 1, k + 1){
      pos[k + 1 - i] = i;
      corres[k + 1 - i]--;
    }

    int p = k + 1;
    FORI(i, k, 1){
      FOR(j, 0, corres[i]){
        pos[p] = i;
        p++;
      }
    }

    FOR(i, 1, n + 1) cout << pos[i] << " ";
    cout << "\n";
  }

  return 0;
}
