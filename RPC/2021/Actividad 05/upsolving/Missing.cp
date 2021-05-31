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
  
  int n, id = 1, sz = 1, pos = 0;
  string s, r;
  cin >> n >> s;
  
  FOR(i, 0, n){
    if(id == 10 or id == 100) sz++;
    if(s.substr(pos, sz) != to_string(id)){
      cout << id << "\n";
      break;
    }
    id++;
    pos += sz;
  }
  
  return 0;
}