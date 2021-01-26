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

int ans, m;

bool com(int &a, int &b){
  return a > b;
}

void use(int &i, deque<int> &d, bool id){
  m -= d[i];
  i++;
  if(id) ans++;
  else ans += 2;
  return;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  int t, n, a, b, lu, ld;
  cin >> t;
  FOR(ab, 0, t){
    cin >> n >> m;
    deque<int> uno, dos, p(n);
    FOR(i, 0, n) cin >> p[i];
    FOR(i, 0, n){
      cin >> ans;
      if(ans == 1) uno.PB(p[i]);
      else dos.PB(p[i]);
    }
    
    sort(uno.begin(), uno.end(), com);
    sort(dos.begin(), dos.end(), com);
    
    a = b = 0;
    deque<ll> pu(uno.size() + 1), pd(dos.size() + 1);
    pd.PB(0);
    pu.PB(0);
    b = dos.size();
    FOR(i, 1, dos.size() + 1){
      pd[i] = dos[i - 1] + pd[i - 1];
      if(pd[i] >= m){
        b = i;
        break;
      }
    }
    ans = INF;
    if(pd[b] >= m) ans = 2*b;
    
    FOR(i, 1, uno.size() + 1){
      pu[i] = uno[i - 1] + pu[i - 1];
      if(pu[i] + pd[b] >= m){
        FORI(j, b - 1, 0){
          if(pu[i] + pd[j] < m){
            b = j + 1;
            break;
          }
          if(j == 0) b = 0;
        }
        ans = min(ans, (int)i + 2*b);
      }
    }
    
    if(ans == INF) cout << "-1\n";
    else cout << ans << "\n";
  }
  
  return 0;
}