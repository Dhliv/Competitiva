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
  string uno, dos;
  int a, b, res;
  vector<vector<string> > ans(5);
  ans[1].PB("00");
  ans[1].PB("01");
  ans[1].PB("81");
  
  ans[2].PB("0000");
  ans[2].PB("0001");
  ans[2].PB("2025");
  ans[2].PB("3025");
  ans[2].PB("9801");
  
  uno = "000000";
  dos = "000001";
  ans[3].PB(uno);
  ans[3].PB(dos);
  ans[3].PB("088209");
  ans[3].PB("494209");
  ans[3].PB("998001");
  
  uno = "00000000";
  dos = "00000001";
  ans[4].PB(uno);
  ans[4].PB(dos);
  ans[4].PB("04941729");
  ans[4].PB("07441984");
  ans[4].PB("24502500");
  ans[4].PB("25502500");
  ans[4].PB("52881984");
  ans[4].PB("60481729");
  ans[4].PB("99980001");
  
  
  while(cin >> a){
    a /= 2;
    FOR(i, 0, ans[a].size()) cout << ans[a][i] << "\n";
  }
  
  return 0;
}