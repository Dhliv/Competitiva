#include <bits/stdc++.h>
#define LINF LLONG_MAX
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
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORI(i, a, b) for(int i = a; i >= b; i--)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int maxi(vector<int> &num, int a, int b){
  int ans = num[a];
  
  FOR(i, a + 1, b + 1){
    if(ans < num[i]) ans = num[i];
  }
  
  return ans;
}

int main(){
  int t, n, cont, con;
  ll ans;
  bool pos;
  cin >> t;
  
  FOR(a, 0, t){
    cin >> n;
    vector<int> num(n), res, ax;
    pos = true;
    cont = con = ans = 0;
    FOR(i, 0, n) cin >> num[i];
    
    FOR(i, 0, n){
      if(pos and num[i] > 0){
        pos = false;
        ax.PB(i);
        con++;
      }else if(!pos and num[i] < 0){
        pos = true;
        ax.PB(i);
        con++;
      }
    }
    
    pos = false;
    res.swap(ax);
    
    FOR(i, 0, n){
      if(pos and num[i] > 0){
        pos = false;
        ax.PB(i);
        cont++;
      }else if(!pos and num[i] < 0){
        pos = true;
        ax.PB(i);
        cont++;
      }
    }
    
    if(cont > con) res.swap(ax);
    
    cont = max(cont, con);
    
    FOR(i, 0, res.size() - 1){
      ans += maxi(num, res[i], res[i + 1] - 1);
    }
    
    ans += maxi(num, res[res.size() - 1], n - 1);
    
    cout << ans << "\n";
  }
  
  return 0;
}