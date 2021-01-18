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
  int d, pos, k = 0, n, end = 0;
  vector<int> q;
  deque<int> pr;
  
  while(cin >> d) q.PB(d);
  n = q.size();
  
  vector<int> l(n), lid(n), p(n, -1);
  
  FOR(i, 0, n){
    pos = lower_bound(l.begin(), l.begin() + k, q[i]) - l.begin();
    l[pos] = q[i];
    lid[pos] = i;
    p[i] = pos ? lid[pos - 1] : -1;
    
    if(pos + 1 == k) end = i;
    else if(pos == k){
      k++;
      end = i;
    }
  }
  
  cout << k << "\n-\n";
  
  while(end != -1){
    pr.PF(q[end]);
    end = p[end];
  }
  
  FOR(i, 0, pr.size()) cout << pr[i] << "\n";
  
  return 0;
}