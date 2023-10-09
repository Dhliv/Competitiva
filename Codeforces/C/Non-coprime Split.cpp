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

  int MAX = 20000;
  vector<int> prs;
  vector<int> notPrime(MAX);

  FOR(i, 2, MAX){
    if(notPrime[i]) continue;
    prs.PB(i);
    for(int j = i*i; j < MAX; j += i) notPrime[j] = 1;
  }

  int t, l, r; cin >> t;
  while(t--){
    cin >> l >> r;

    if(r < 4){
      cout << "-1\n";
      continue;
    }

    if(r != l){
      int val = l - 2 + l%2;
      cout << "2 " << (val > 0 ? val : 2) << "\n";
      continue;
    }

    bool isPr = true;
    FOR(i, 0, prs.size()){
      if(l%prs[i] == 0 and l != prs[i]){
        isPr = false;
        break;
      }
    }

    if(isPr){
      cout << "-1\n";
      continue;
    }

    FOR(i, 0, prs.size()){
      if(l%prs[i] == 0){
        cout << prs[i] << " " << l - prs[i] << "\n";
        break;
      }
    }
  }

  return 0;
}