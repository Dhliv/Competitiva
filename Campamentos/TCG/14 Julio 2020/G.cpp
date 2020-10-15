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
  int a, b, s, res = 0;
  cin >> a >> b >> s;
  res += abs(a);
  res += abs(b);
  
  if(s < res) cout << "No\n";
  else if(s == res) cout << "Yes\n";
  else if(res%2 == s%2) cout << "Yes\n";
  else cout << "No\n";
  
  return 0;
}