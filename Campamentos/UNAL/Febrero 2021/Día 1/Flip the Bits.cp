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
  int cases, n, ans;
  cin >> cases;
  
  FOR(ab, 0, cases){
    cin >> n;
    FOR(i, 0, 31){
      if(n & (1 << i)){
        cout << i + 1 << "\n";
        break;
      }
    }
  }
  
  return 0;
}