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

  int n; cin >> n;
  string s;

  FOR(ab, 0, n){
    vector<int> p(3);
    cin >> s;

    FOR(i, 0, s.size()) p[s[i] - 'A']++;

    if(p[0] + p[2] == p[1]) cout << "YES\n";
    else cout << "NO\n";
  }
 
  return 0;
} 