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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)

using namespace std;

int main(){
  int n, sum, low, up, pos, neg;
  double x;
  cout.precision(2);
  
  while(cin >> n, n){
    vector<int> v(n);
    sum = neg = pos = 0;
    
    FOR(i, 0, n){
      cin >> x;
      x *= 100;
      v[i] = (x + 0.0000001);
      sum += v[i];
    }
    
    low = up = sum/n;
    if(sum%n) up++;
    
    FOR(i, 0, n){
      if(v[i] < low) neg += low - v[i];
      if(v[i] > up) pos += v[i] - up;
    }
    
    sum = max(pos, neg);
    x = (1.0*sum)/100;
    
    cout << fixed << "$" << x << "\n";
  }
  
  return 0;
}
