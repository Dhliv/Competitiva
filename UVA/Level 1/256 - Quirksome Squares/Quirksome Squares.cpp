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
  
  FOR(i, 0, 10000){
    a = i/100;
    b = i%100;
    res = pow(a + b, 2);
    if(res == i){
      uno = dos = "";
      FOR(j, 1, 2){
        if(a/(int (pow(10, j))) == 0) uno += '0';
        if(b/(int (pow(10, j))) == 0) dos += '0';
      }
      uno += to_string(a);
      dos += to_string(b);
      ans[2].PB(uno + dos);
    }
  }
  
  uno = "000000";
  dos = "000001";
  ans[3].PB(uno);
  ans[3].PB(dos);
  
  FOR(i, 1000, 1000000){
    a = i/1000;
    b = i%1000;
    res = pow(a + b, 2);
    if(res == i){
      uno = dos = "";
      FOR(j, 1, 3){
        if(a/(int (pow(10, j))) == 0) uno += '0';
        if(b/(int (pow(10, j))) == 0) dos += '0';
      }
      uno += to_string(a);
      dos += to_string(b);
      ans[3].PB(uno + dos);
    }
  }
  
  uno = "00000000";
  dos = "00000001";
  ans[4].PB(uno);
  ans[4].PB(dos);
  
  FOR(i, 10000, 100000000){
    a = i/10000;
    b = i%10000;
    res = pow(a + b, 2);
    if(res == i){
      uno = dos = "";
      FOR(j, 1, 4){
        if(a/(int (pow(10, j))) == 0) uno += '0';
        if(b/(int (pow(10, j))) == 0) dos += '0';
      }
      uno += to_string(a);
      dos += to_string(b);
      ans[4].PB(uno + dos);
    }
  }
  
  while(cin >> a){
    a /= 2;
    FOR(i, 0, ans[a].size()) cout << ans[a][i] << "\n";
  }
  
  return 0;
}