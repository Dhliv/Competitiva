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

  int n, mini = 1, x; cin >> n;
  map<int, int> p;
  FOR(i, 0, n){
    cin >> x;
    auto it = p.find(x);
    if(it != p.end()) it->s++;
    else p.insert(MP(x, 1));
  }

  if(p.size() == 1 and (p.begin()->f) == 1){
    FOR(i, 0, n - 1) cout << "1 ";
    cout << "2\n";
  }else{
    cout << mini;
    auto it = p.begin();
    auto end = p.end();
    int ele = 1;
    for(; it != end and ele != n; it++){
      FOR(i, 0, it->s){
        if(ele == n) break;
        cout << " " << it->f;
        ele++;
      }
    }
    cout << "\n";
  }

  return 0;
}
