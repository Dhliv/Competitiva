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
  int n, a, b;
  bool start;
  string nue, ent;
  set<string> w;
  
  while(getline(cin, ent)){
    nue = "";
    ent += "#";
    
    FOR(i, 0, ent.size()){
      a = ent[i] - 'a', b = ent[i] - 'A';
      if((a >= 0 and a <= 25) or (b >= 0 and b <= 25)) nue += tolower(ent[i]);
      else if(nue.size()){
        w.insert(nue);
        nue = "";
      }
    }
  }

  for(auto x: w) cout << x << "\n";
  
  return 0;
}