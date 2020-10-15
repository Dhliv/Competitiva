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
  int val, ele, med, a1, a2, x;
  cin >> ele;
  
  map<int, int> v;
  
  FOR(i, 0, ele){
    cin >> val;
    v[val] = 0;
  }
  
  if(v.size() > 3)
    cout << "NO\n";
  else if(v.size() < 3)
    cout << "YES\n";
  else{
    a1 = (++v.begin())->first - v.begin()->first;
    a2 = (++(++v.begin()))->first - (++v.begin())->first;
    
    if(a1 == a2)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  
  return 0;
}