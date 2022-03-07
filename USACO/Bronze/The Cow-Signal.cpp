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

int n, m, k;
string s;

void amplify(){
  string ans = "";

  FOR(i, 0, m){
    FOR(j, 0, k){
      ans.PB(s[i]);
    }
  }

  s = ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("cowsignal.in");
  ofstream cout("cowsignal.out");

  cin >> n >> m >> k;

  FOR(i, 0, n){
    cin >> s;
    amplify();

    FOR(j, 0, k) cout << s << "\n";
  }

  return 0;
}
