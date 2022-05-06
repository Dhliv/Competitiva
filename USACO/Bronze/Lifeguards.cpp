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

  ifstream cin;
  cin.open("lifeguards.in");
  ofstream cout("lifeguards.out");

  int n; cin >> n;
  vector<int> has(1001);
  vector<pair<int, int> > p(n);

  FOR(i, 0, n){
    cin >> p[i].f >> p[i].s;

    FOR(j, p[i].f + 1, p[i].s + 1) has[j]++;
  }

  int maxi = 0, act;
  FOR(i, 0, n){
    act = 0;
    FOR(j, p[i].f + 1, p[i].s + 1) has[j]--;

    FOR(j, 0, 1001) if(has[j]) act++;
    maxi = max(maxi, act);

    FOR(j, p[i].f + 1, p[i].s + 1) has[j]++;
  }

  cout << maxi << "\n";

  return 0;
}