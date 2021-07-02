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
  
  int t, n, m, x;
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> n;
    m = 2*n;
    deque<int> p, ip;
    
    FOR(i, 0, m){
      cin >> x;
      
      if(x & 1) ip.PB(i + 1);
      else p.PB(i + 1);
    }
    
    if(p.size() & 1){
      p.P_B();
      ip.P_B();
    }else{
      if(ip.size()) p.swap(ip);
      p.P_B();
      p.P_B();
    }
    
    for(int i = 0; i < p.size(); i += 2) cout << p[i] << " " << p[i + 1] << "\n";
    for(int i = 0; i < ip.size(); i += 2) cout << ip[i] << " " << ip[i + 1] << "\n";
  }
  
  return 0;
}