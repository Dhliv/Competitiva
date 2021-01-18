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

string find(string x, map<string, string> &p){
  string fx = p[x];
  if(fx == x) return x;
  return p[x] = find(fx, p);
}

int main(){
  int cases, m, ans;
  cin >> cases;
  string a, b, fa, fb;
  
  FOR(ab, 0, cases){
    cin >> m;
    map<string, string> p;
    map<string, int> sum;
    
    FOR(i, 0, m){
      cin >> a >> b;
      ans = 1;
      if(a != b){
        if(p.find(a) != p.end()){
          fa = find(a, p);
          if(p.find(b) != p.end()){
            fb = find(b, p);
            if(fb != fa){
              sum[fb] += sum[fa];
              p[fa] = fb;
            }
            ans = sum[fb];
          }else{
            p.insert(MP(b, fa));
            sum[fa]++;
            ans = sum[fa];
          }
        }else if(p.find(b) != p.end()){
          fb = find(b, p);
          if(p.find(a) != p.end()){
            fa = find(a, p);
            if(fb != fa){
              sum[fb] += sum[fa];
              p[fa] = fb;
            }
          }else{
            sum[fb]++;
            p.insert(MP(a, fb));
          }
          ans = sum[fb];
        }else{
          p.insert(MP(b, b));
          p.insert(MP(a, b));
          sum.insert(MP(b, 2));
          ans = 2;
        }
      }else if(p.find(a) != p.end()){
        fb = find(a, p);
        ans = sum[fb];
      }
      
      cout << ans << "\n";
    }
  }
  
  return 0;
}