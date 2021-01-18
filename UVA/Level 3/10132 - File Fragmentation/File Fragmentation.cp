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
  int cases, n, maxi;
  cin >> cases;
  string a, uno, dos, ans;
  getline(cin, a);
  getline(cin, a);
  
  FOR(b, 0, cases){
    if(b) cout << "\n";
    
    map<string, int> s;
    deque<string> p;
    
    while(getline(cin, a)){
      if(a.size() == 0) break;
      p.PB(a);
    }
    
    n = p.size();
    FOR(i, 0, n){
      FOR(j, i + 1, n){
        uno = p[i] + p[j];
        dos = p[j] + p[i];
        if(s.find(uno) != s.end()) s[uno]++;
        else s.insert(MP(uno, 1));
        if(uno != dos){
          if(s.find(dos) != s.end()) s[dos]++;
          else s.insert(MP(dos, 1));
        }
      }
    }
    
    maxi = 0;
    for(auto x: s){
      if(x.s > maxi){
        maxi = x.s;
        ans = x.f;
      }
    }
    
    cout << ans << "\n";
  }
  
  return 0;
}