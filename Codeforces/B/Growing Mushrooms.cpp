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
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

bool comp(pair<double, int> a, pair<double, int> b){
  if(a.f == b.f)
    return a.s < b.s;
  return a.f > b.f;
}

int main(){
  int n, t1, t2, k, v1, v2;
  double a, b;
  cin >> n >> t1 >> t2 >> k;
  vector<pair<double, int> > v(n);
  
  FOR(i, 0, n){
    cin >> v1 >> v2;
    a = (v1*1.0)*t1*(1.0 - (k*1.0)/100.0) + (v2*1.0)*t2;
    b = (v2*1.0)*t1*(1.0 - (k*1.0)/100.0) + (v1*1.0)*t2;
    
    v[i] = MP(max(a, b), i + 1);
  }
  
  sort(v.begin(), v.end(), comp);
  cout.precision(2);
  
  FOR(i, 0, n)
    cout << v[i].s << " "  << fixed << v[i].f << "\n";
  
  return 0;
}