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
  string a, ans = "", s = " ";
  int n, pos;
  bool c;
  getline(cin, ans);
  deque<string> imp;
  
  FOR(i, 0, ans.size()){
    n = ans[i] - 'a';
    if(!isspace(ans[i]) and (n < 0 or n > 25)){
      a += " ";
      a += ans[i];
      a += " ";
    }else a += ans[i];
  }
  
  a += " ";
  pos = 0;
  FOR(i, 0, a.size()){
    if(isspace(a[i])){
      if(i == pos) pos++;
      else{
        imp.PB(a.substr(pos, i - pos));
        pos = i + 1;
      }
    }
  }
  
  FOR(i, 1, imp.size()){
    n = imp[i][0] - 'a';
    if(n < 0 or n > 25){
      imp[i - 1] += imp[i][0];
      if(imp[i].size() == 1) imp[i] = "";
      else imp[i] = imp[i].substr(1);
    }else imp[i - 1] += " ";
  }
  
  FOR(i, 0, imp.size()) cout << imp[i];
  cout << "\n";
  
  return 0;
}