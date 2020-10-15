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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
 int n, un, dos, ans = 0, g, doble = 0;
 cin >> n >> un >> dos;
 
 FOR(i, 0, n){
   cin >> g;
   
   if(g == 1){
     if(un > 0) un--;
     else if(dos > 0) dos--, doble++;
     else if(doble > 0) doble--;
     else ans++;
   }else{
     if(dos > 0) dos--;
     else ans += 2;
   }
 }
 
 cout << ans << "\n";
  
  return 0;
}