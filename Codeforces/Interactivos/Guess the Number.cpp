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
  int low = 1, high = 1000000, mid;
  string ent;
  
  while(low <= high){
    mid = (low + high)/2;
    cout << mid << endl;
    cin >> ent;
    
    if(ent == "<") high = mid - 1;
    else low = mid + 1;
  }
  
  cout << "! " << to_string(high) << endl;
  
  return 0;
}
