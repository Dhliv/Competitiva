#include <bits/stdc++.h>
#define INF 1000000000
#define ll long long
#define PB push_back
#define PF push_front
#define P_F pop_front
#define P_B pop_back
#define F front
#define B back
#define MP make_pair
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int much1, much2;
  double ratio, mini, maxi;
  string a, b;
  
  cout.precision(4);
  
  while(getline(cin, a)){
    getline(cin, b);
    much1 = much2 = 0;
    
    FOR(i, 0, a.size()){
      if(0 < (a[i] - 'a' + 1) and (a[i] - 'a' + 1) < 27)
        much1 += a[i] - 'a' + 1;
      else if(0 < (a[i] - 'A' + 1) and (a[i] - 'A' + 1) < 27)
        much1 += a[i] - 'A' + 1;
    }
    
    FOR(i, 0, b.size()){
      if(0 < (b[i] - 'a' + 1) and (b[i] - 'a' + 1) < 27)
        much2 += b[i] - 'a' + 1;
      else if(0 < (b[i] - 'A' + 1) and (b[i] - 'A' + 1) < 27)
        much2 += b[i] - 'A' + 1;
    }
    
    a = to_string(much1);
    b = to_string(much2);
    
    while(a.size() > 1){
      much1 = 0;
      FOR(i, 0, a.size()){
        much1 += a[i] - '0';
      }
      a = to_string(much1);
    }
    
    while(b.size() > 1){
      much2 = 0;
      FOR(i, 0, b.size()){
        much2 += b[i] - '0';
      }
      b = to_string(much2);
    }
    
    mini = min(much1, much2);
    maxi = max(much1, much2);
    ratio = (mini/maxi)*100.0;
    
    if(fmod(ratio, 1.0) == 0.0)
      cout << ratio << ".00 %\n";
    else if(ratio >= 10.0)
      cout << ratio << " %\n";
  }
  
  return 0;
}