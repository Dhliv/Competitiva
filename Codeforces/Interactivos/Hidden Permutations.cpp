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

  int t, n, d, left, x, last; cin >> t;

  FOR(ab, 0, t){
    cin >> n;
    vector<int> h(n + 1), p(n + 1);
    deque<int> loop;
    left = n;
    last = 1;

    while(left != 0){
      loop.clear();

      FOR(j, last, n + 1){
        if(h[j] == 0){
          last = j;
          break;
        }
      }

      while(true){
        cout << "? " << last << endl;
        cin >> x;

        if(h[x]) break;
        h[x] = 1;
        loop.PB(x);
      }

      left -= loop.size();
      FOR(i, 1, loop.size()) p[loop[i - 1]] = loop[i];
      p[loop[loop.size() - 1]] = loop[0];
    }

    cout << "!";
    FOR(i, 1, n + 1) cout << " " << p[i];
    cout << endl;
  }

  return 0;
}
