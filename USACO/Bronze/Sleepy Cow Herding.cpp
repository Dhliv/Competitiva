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

  ifstream cin("herding.in");
  ofstream cout("herding.out");

  vector<int> p(3); FOR(i, 0, 3) cin >> p[i];
  sort(p.begin(), p.end());
  int mini, maxi;

  if(p[1] - p[0] == 2 or p[2] - p[1] == 2) mini = 1;
  else if(p[1] - p[0] == 1 and p[2] - p[1] == 1) mini = 0;
  else mini = 2;

  maxi = max({0, p[1] - p[0] - 1, p[2] - p[1] - 1});

  cout << mini << "\n" << maxi << "\n";

  return 0;
}
