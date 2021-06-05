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
  
  int t, n, x, pos;
  string a;
  bool abl;
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> n;
    cin >> x;
    deque<int> q;
    a = to_string(x);
    q.PB(x);
    cout << a << "\n";
    
    FOR(i, 1, n){
      cin >> x;
      abl = false;
      
      FORI(i, q.size() - 1, 0){
        if(x == q[i] + 1){
          abl = true;
          pos = i;
          q[i] = x;
          break;
        }
      }
      
      if(abl){
        deque<int> ax;
        
        FOR(i, 0, pos + 1) ax.PB(q[i]);
        
        a = to_string(ax[0]);
        FOR(i, 1, ax.size()) a += "." + to_string(ax[i]);
        swap(ax, q);
      }else{
        a += "." + to_string(x);
        q.PB(x);
      }
      
      cout << a + "\n";
    }
  }
  
  return 0;
}