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
 
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n, x, act; cin >> t;
  bool able;

  FOR(ab, 0, t){
    cin >> n;
    priority_queue<int> p;
    act = n;
    able = 1;

    FOR(i, 0, n){
      cin >> x;
      while(x > n) x /= 2;
      p.push(x);
    }

    while(act > 0){
      while(p.top() > act){
        x = p.top()/2; p.pop();
        p.push(x);
      }

      if(p.top() == act){
        act--;
        p.pop();
      }
      else{
        able = false;
        break;
      }
    }

    cout << (able ? "yes" : "no") << "\n";
  }
  
  return 0;
}
