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

  string s, ans = "", acum = "";
  bool dos = false;
  cin >> s;

  FOR(i, 0, s.size()){
    if(s[i] == '2') dos = true;

    if(dos){
      if(s[i] == '1') ans.PB('1');
      else acum.PB(s[i]);
    }else{
      if(s[i] == '1') acum.PB('1');
      else ans.PB(s[i]);
    }
  }

  cout << ans + acum + "\n";
 
  return 0;
} 