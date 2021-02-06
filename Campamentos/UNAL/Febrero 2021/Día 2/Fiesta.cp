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

int find(int &x, vector<int> &p){
  if(x == p[x]) return x;
  return p[x] = find(p[x], p);
}

void com(int &a, int &b, int ti, vector<int> &pa, vector<int> &p, vector<int> &sums, vector<int> &t){
  int fa, fb;
  fa = find(a, pa);
  fb = find(b, pa);
  if(fa == fb) return;
  
  if(sums[fa] >= sums[fb]){
    t[fb] = ti;
    p[fb] = fa;
    pa[fb] = fa;
    sums[fa] += sums[fb];
  }else{
    t[fa] = ti;
    p[fa] = fb;
    pa[fa] = fb;
    sums[fb] += sums[fa];
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, q, e, x, y, id = 1, xf, yf;
  bool able;
  cin >> n >> q;
  
  vector<int> p(n + 1), sums(n + 1, 1), t(n + 1, 0), s(n + 1), times(n + 1), pa(n + 1);
  FOR(i, 1, n + 1) p[i] = i, pa[i] = i;
  
  FOR(i, 0, q){
    cin >> e >> x >> y;
    
    if(e == 1) com(x, y, i + 1, pa, p, sums, t);
    else{
      if(x == y) cout << "0\n";
      else{
        yf = find(y, pa);
        xf = find(x, pa);
        if(yf != xf) cout << ":(\n";
        else{
          deque<int> pq;
          if(sums[xf] > sums[yf]) swap(x, y);
          pq.PB(x);
          s[x] = id;
          times[x] = 0;
          
          while(!pq.empty()){
            x = pq.F();
            pq.P_F();
            
            xf = p[x];
            if(x != xf){
              s[xf] = id;
              times[xf] = t[x];
              pq.PB(xf);
            }
          }
          
          if(s[y] == id) cout << times[y] << "\n";
          else{
            pq.PB(y);
            while(!pq.empty()){
              x = pq.F();
              pq.P_F();
              
              xf = p[x];
              if(s[xf] != id){
                if(x != xf) pq.PB(xf);
              }else{
                cout << max(t[x], times[xf]) << "\n";
                break;
              }
            }
          }
          id++;
        }
      }
    }
  }
  
  return 0;
}