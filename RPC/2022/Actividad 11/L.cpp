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
#define PI 3.14159265358979323846

using namespace std;

const ld EPSILON = 0.0000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s, g, ans; cin >> s;
  int hash[255] = {0};
  FOR(i, 0, s.size()) hash[s[i]] = 1;

  FOR(i, 0, 7){
    cin >> g;
    if(g == s){
      cout << "WINNER\n";
      return 0;
    }

    string aux = g;
    FOR(j, 0, s.size()){
      if(s[j] == g[j]) aux[j] = 'G';
      else if(hash[g[j]]) aux[j] = 'Y';
      else aux[j] = 'X';
    }

    if(i == 6) cout << "LOSER\n";
    else cout << aux << "\n";
  }
  
  return 0;
}