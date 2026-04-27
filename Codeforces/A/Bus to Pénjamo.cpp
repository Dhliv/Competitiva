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

  int t; cin >> t;
  FOR(i, 0, t){
    int n, r; cin >> n >> r;
    int persons = 0;
    int happy = 0;

    FOR(i, 0, n) {
      int p; cin >> p;
      happy += (p/2)*2;
      persons += p%2;
      r -= p/2;
    }

    while(persons/2 < r and persons) {
      happy++;
      persons--;
      r--;
    }

    cout << happy << '\n';
  }
  
  return 0;
}