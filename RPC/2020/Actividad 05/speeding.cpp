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

int main() {
  int x[110],t[110],n,vMax=0;
  cin>>n;
  FOR(i,0,n){
    cin>>t[i]>>x[i];
  }
  FOR(i,1,n){
    if( (x[i]-x[i-1])/(t[i]-t[i-1]) > vMax) 
        vMax = (x[i]-x[i-1])/(t[i]-t[i-1]);
  }

  cout << vMax << endl;
  return 0;
}




/*
int main() {
  int x[110],t[110],n,vMax=0;
  cin>>n;
  FOR(i,0,n){
    cin>>x[i]>>t[i];
  }
  FOR(i,1,n){
    if( (x[i]-x[i-1])/(t[i]-t[i-1]) > vMax) 
        vMax = (x[i]-x[i-1])/(t[i]-t[i-1]);
  }

  cout << vMax << endl;
  return 0;
}

*/