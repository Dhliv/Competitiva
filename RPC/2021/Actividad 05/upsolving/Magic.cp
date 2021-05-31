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
  
  string s;
  int x;
  cin >> s;
  vector<int> p(26);
  bool able = true;
  
  FOR(i, 0, s.size()){
    x = s[i] - 'a';
    if(p[x]) able = false;
    p[x]++;
  }
  
  if(able) cout << "1\n";
  else cout << "0\n";
  
  return 0;
}