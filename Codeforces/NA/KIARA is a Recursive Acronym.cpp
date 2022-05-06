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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n; cin >> n;
  bool hash[250] = {0};
  vector<string> p(n);
  FOR(i, 0, n){
    cin >> p[i];
    hash[p[i][0]] = 1;
  }

  bool able;
  FOR(i, 0, n){
    able = true;

    FOR(j, 0, p[i].size()){
      if(!hash[p[i][j]]) {
        able = false;
        break;
      }
    }

    if(able) {
      cout << "Y\n";
      return 0;
    }
  }

  cout << "N\n";

  return 0;
}
