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
#define MAX 5001

using namespace std;

const ld EPSILON = 0.0000000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int n, a, b;
  string s;

  while(t--){
    cin >> n >> s;
    int A, B;
    A = B = 0;
    int p;
    int GA, GB;
    GA = GB = 0;

    FOR(i, 1, n + 1){ // y
      FOR(j, 1, n + 1){ // x
        A = B = a = b = 0;
        int cnt = 0;
        FOR(k, 0, n){
          if(s[k] == 'A') a++;
          else b++;
          cnt++;
          if(a == j or b == j){
            if(a == j) A++;
            else B++;
            a = b = 0;
            if(A == i or B == i) break;
          }
        }

        if(cnt != n or a or b or (A != i and B != i)) continue;
        if(A > B) GA++;
        else if(A < B) GB++;
      }
    }

    //cout << GA << " && " << GB << " -> ";
    if(GA == GB) cout << "?\n";
    else if(GA > GB) cout << "A\n";
    else cout << "B\n";
  }

  return 0;
}