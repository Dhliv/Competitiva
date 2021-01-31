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
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, t, h, p, l;
  string name;
  pair<int, pair<int, string> > x;
  
  while(cin >> n){
    priority_queue<pair<int, pair<int, string> > > pq;
    FOR(a, 0, n){
      cin >> t;
      if(t == 1){
        cin >> h >> p >> name;
        pq.push(MP(-p, MP(-h, name)));
      }else{
        cin >> l;
        x = pq.top();
        pq.pop();
        
        cout << -x.s.f << " " << l << " " << (l + x.s.f) << " " << x.s.s << "\n";
      }
    }
  }

  return 0;
}