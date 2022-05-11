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
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s; cin >> s;
  int hash[26] = {0};

  bool p, ip;
  p = ip = false;
  FOR(i, 0, s.size()) hash[s[i] - 'a']++;

  FOR(i, 0, 26){
    if(hash[i] == 0) continue;
    if(hash[i] & 1) ip = true;
    else p = true;
  }

  if(ip && p) cout << "0/1\n";
  else if(p) cout << "0\n";
  else cout << "1\n";

  return 0;
}