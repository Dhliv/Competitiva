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
  int n, k, a;
  ll sum = 0;
  cin >> n >> k;
  priority_queue<int> q;
  
  FOR(i, 0, n){
    cin >> a;
    q.push(-a);
  }
  
  FOR(i, 0, k){
    a = q.top();
    q.pop();
    q.push(-a);
  }
  
  while(!q.empty()){
    sum -= q.top();
    q.pop();
  }
  
  cout << sum << "\n";
  
  return 0;
}
