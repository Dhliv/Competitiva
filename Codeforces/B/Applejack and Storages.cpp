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
  int n, a, b;
  cin >> n;
  vector<int> tabs(100010);
  ll sum2 = 0, sum4 = 0;
  char k;
  
  FOR(i, 0, n){
    cin >> a;
    sum4 -= tabs[a]/4;
    sum2 -= tabs[a]/2;
    
    tabs[a]++;
    
    sum4 += tabs[a]/4;
    sum2 += tabs[a]/2;
  }
  
  cin >> b;
  FOR(i, 0, b){
    cin >> k >> a;
    sum4 -= tabs[a]/4;
    sum2 -= tabs[a]/2;
    
    if(k == '+') tabs[a]++;
    else tabs[a]--;
    
    sum4 += tabs[a]/4;
    sum2 += tabs[a]/2;
    
    if(sum4 >= 1 and sum2 >= 4) cout << "YES\n";
    else cout << "NO\n";
  }
  
  return 0;
}
