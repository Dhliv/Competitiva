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
#define FORI(i, a, b) for(int i = a; i >= b; i--)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  ll cases, t, next, pos, press, s, forw, backw;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> t >> s;
    press = 0;
    vector<int> songs(s);
    
    FOR(i, 0, s) cin >> songs[i];
    
    FOR(i, 0, s - 1){
      next = songs[i]%t + 1;
      
      if(next != songs[i + 1]){
        if(next < songs[i + 1]){
          forw = songs[i + 1] - next;
          backw = next + t - songs[i + 1];
        }else{
          backw = next - songs[i + 1];
          forw = songs[i + 1] + t - next;
        }
        press += min(forw, backw);
      }
    }
    
    cout << press << "\n";
  }
  
  return 0;
}