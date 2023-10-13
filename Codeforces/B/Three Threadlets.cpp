#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_mini
#define ll long long
#define ull unsigned long long
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
#define PI 3.14159265358979323846
 
using namespace std;
 
const ld EPSILON = 0.000000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int a, b, c, mini;

  while(t--){
    int x, y;
    cin >> a >> b >> c;
    mini = min(a, min(b, c));
    priority_queue<int> pq;
    pq.push(a);
    pq.push(b);
    pq.push(c);

    if(a == b and a == c){
      cout << "YES\n";
      continue;
    }

    bool able = false;
    FOR(i, 0, 3){
      x = pq.top();
      pq.pop();

      //cout << "Replacing " << x << " -> ";
      y = x - mini;
      x = mini;
      mini = min(y, mini);

      //cout << "New elements: " << x << " " << y << "\n";

      deque<int> q;
      q.PB(x); q.PB(y);
      while(!pq.empty()){
        q.PB(pq.top());
        pq.pop();
      }

      int cnt = 1;
      int bef = q[0];
      FOR(j, 1, q.size()){
        if(q[j] != bef) break;
        cnt++;
      }

      if(cnt == q.size()){
        able = true;
        break;
      }

      while(!q.empty()){
        pq.push(q.F());
        q.P_F();
      }
    }

    cout << (able ? "YES" : "NO") << "\n";
  }

  return 0;
}