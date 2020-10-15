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
 int n, ta = 0, tb = 0, aa = 1, ab = 1;
 cin >> n;
 deque<int> v(n);
 
 FOR(i, 0, n) cin >> v[i];
 
 if(n > 1){
   ta = v.F();
   tb = v.B();
   v.P_F();
   v.P_B();
   
   while(v.size()){
     while(ta <= tb and v.size()){
       aa++;
       ta += v.F();
       v.P_F();
     }
     while(tb < ta and v.size()){
       ab++;
       tb += v.B();
       v.P_B();
     }
   }
   
   cout << aa << " " << ab << "\n";
 }else
  cout << 1 << " " << 0 << "\n";
  
  return 0;
}