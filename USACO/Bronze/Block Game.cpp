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
  cin.open("blocks.in");
  ofstream cout("blocks.out");

  int n; cin >> n;
  int total[26] = {0};
  string a, b;

  FOR(ab, 0, n){
    cin >> a >> b;
    vector<int> ca(26), cb(26);

    FOR(i, 0, a.size()) ca[a[i] - 'a']++;
    FOR(i, 0, b.size()) cb[b[i] - 'a']++;

    FOR(i, 0, 26) total[i] += max(ca[i], cb[i]);
  }

  FOR(i, 0, 26) cout << total[i] << "\n";
  
  return 0;
}
