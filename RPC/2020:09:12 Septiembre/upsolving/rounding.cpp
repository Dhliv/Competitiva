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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  ll n, a = 0, b = 0;
  cin >> n;
  
  while(n%2 == 0){
    a++;
    n /= 2;
  }
  
  while(n%5 == 0){
    b++;
    n /= 5;
  }
  
  vector<ll> dp2(61), dp5(27);
  dp2[0] = dp5[0] = 1;
  
  FOR(i, 1, 61) dp2[i] = 2*dp2[i - 1];
  FOR(i, 1, 27) dp5[i] = 5*dp5[i - 1];
  
  priority_queue<ll> q;
  
  for(int i = 0; i <= a; i++){
    for(int j = 0; j <= b; j++){
      n = dp2[i]*dp5[j];
      q.push(-n);
    }
  }
  
  cout << q.size() << "\n";
  
  while(!q.empty()){
    cout << -q.top() << "\n";
    q.pop();
  }
  
  return 0;
}