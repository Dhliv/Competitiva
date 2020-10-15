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
int lon;

int main() {
  int diff1 = 0, diff2 = 0;
  cin >> lon;
  string ori, dest;
  bool pegadas = false;
  cin >> ori >> dest;
  
  FOR(i, 1, lon){
    if(ori[i] != ori[i - 1])
      diff1++;
    if(dest[i] != dest[i - 1])
      diff2++;
    if(dest[i] == dest[i - 1])
      pegadas = true;
  }
  
  if(ori[0] != ori[lon - 1])
    diff1++;
  if(dest[0] != dest[lon - 1])
    diff2++;
    
  if(dest[0] == dest[lon - 1])
    pegadas = true;
  
  if(dest == ori){
    cout << "yes\n";
    return 0;
  }
  
  if(diff1 == 0){
    cout << "no\n";
    return 0;
  }
  
  if(diff1 > diff2){
    cout << "yes\n";
    return 0;
  }
  
  if(diff2 > diff1){
    cout << "no\n";
    return 0;
  }
  
  if(pegadas){
    cout << "yes\n";
    return 0;
  }
  
  cout << "no\n";

	return 0;
}