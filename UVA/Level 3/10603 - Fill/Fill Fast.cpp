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
 
using namespace std;

int dp[201][201][201];

class comp{
public: 
  bool operator() (const pair<int, vector<int> > &a, pair<int, vector<int> > &b){
    return a.f > b.f;
  }
};
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int d, x, t; cin >> t;
  vector<int> o(3);

  FOR(ab, 0, t){
    cin >> o[0] >> o[1] >> o[2] >> d;

    FOR(i, 0, o[0] + 1){
      FOR(j, 0, o[1] + 1){
        FOR(k, 0, o[2] + 1) dp[i][j][k] = -1;
      }
    }

    vector<int> xp(3), yp(3);

    priority_queue<pair<int, vector<int> >, vector<pair<int, vector<int> > >, comp> q;
    dp[0][0][o[2]] = 0;
    xp[2] = o[2];
    q.push(MP(0, xp));
    vector<int> s(201, INF);
    s[0] = 0;
    s[o[2]] = 0;

    while(!q.empty()){
      xp = q.top().s;
      q.pop();

      FOR(i, 0, 3){
        FOR(j, 0, 3){
          if(i == j) continue;
          yp = xp;
          x = min(xp[i], o[j] - xp[j]);
          yp[i] -= x;
          yp[j] += x;

          if(dp[yp[0]][yp[1]][yp[2]] != -1) continue;
          x += dp[xp[0]][xp[1]][xp[2]];
          dp[yp[0]][yp[1]][yp[2]] = x;
          FOR(k, 0, 3) s[yp[k]] = min(s[yp[k]], x);
          q.push(MP(x, yp));
        }
      }
    }

    FORI(i, d, 0){
      if(s[i] != INF){
        cout << s[i] << " " << i << "\n";
        break;
      }
    }
  }

  return 0;
}
