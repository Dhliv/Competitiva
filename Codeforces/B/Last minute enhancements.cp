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
  int cases, n, di, x;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> n;
    deque<int> hash(2*n + 2);
    di = 0;
    
    FOR(i, 0, n){
      cin >> x;
      if(hash[x]){
        if(!hash[x + 1]){
          di++;
          hash[x + 1] = 1;
        }
      }else{
        di++;
        hash[x] = 1;
      }
    }
    
    cout << di << "\n";
  }
  
  return 0;
}