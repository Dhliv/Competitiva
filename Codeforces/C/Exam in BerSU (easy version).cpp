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

  int n, m, ac, eli;
  cin >> n >> m;
  vector<int> p(n), ans(n);
  priority_queue<int> q, mini;

  FOR(i, 0, n) cin >> p[i];
  ac = p[0];
  q.push(p[0]);
  eli = 0;

  FOR(i, 1, n){
    ac += p[i];

    while(!q.empty() and !mini.empty()){
      if(q.top() > -mini.top()){
        ac -= mini.top();
        eli--;
        q.push(-mini.top());
        mini.pop();
      }else break;
    }

    while(!q.empty() and ac > m){
      mini.push(-q.top());
      ac -= q.top();
      q.pop();
      eli++;
    }

    q.push(p[i]);
    ans[i] = eli;
  }

  FOR(i, 0, n) cout << ans[i] << " ";
  cout << "\n";

  return 0;
}