#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_mini
#define ll long long
#define ull unsigned long long
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

  int t, n, ti, miniall, mini1, mini2; cin >> t;
  string s;

  while(t--){
    cin >> n;
    mini2 = mini1 = miniall = INF;

    FOR(i, 0, n){
      cin >> ti >> s;

      if(s == "11"){
        miniall = min(miniall, ti);
        continue;
      }

      if(s[0] == '1'){
        mini1 = min(mini1, ti);
        continue;
      }

      if(s[1] == '1'){
        mini2 = min(mini2, ti);
      }
    }

    int ans = miniall;

    if(mini2 != INF and mini1 != INF){
      ans = min(ans, mini1 + mini2);
    }

    cout << (ans == INF ? -1 : ans) << "\n";
  }
 
  return 0;
}