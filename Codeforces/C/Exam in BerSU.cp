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
  
  int n, m, cur, x, er, ax;
  cin >> n >> m;
  priority_queue<int> q, eli;
  
  cur = 0;
  FOR(i, 0, n){
    cin >> x;
    cur += x;
    
    while(cur > m and !q.empty()){
      er = q.top();
      q.pop();
      cur -= er;
      eli.push(-er);
    }
    
    while(!eli.empty() and !q.empty()){
      er = -eli.top();
      ax = q.top();
      
      if(ax <= er) break;
      cur -= (ax - er);
      eli.pop();
      q.pop();
      eli.push(-ax);
      q.push(er);
    }
    
    while(cur < m and !eli.empty()){
      er = eli.top();
      if(cur - er > m) break;
      cur -= er;
      q.push(-er);
      eli.pop();
    }
    
    q.push(x);
    cout << eli.size() << " ";
  }
  
  return 0;
}