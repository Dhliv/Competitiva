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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)

using namespace std;

typedef vector<vector<ll> > vll;
ll modu;

vector<vll> DPM(33);

vll multM(vll A, vll B){
  vll res(A.size(), vector<ll> (B[0].size()));
  
  FOR(i, 0, A.size()){
    FOR(k, 0, B.size()){
      FOR(j, 0, B[0].size()){
        res[i][j] = (res[i][j]%modu + ((A[i][k])%modu * (B[k][j])%modu)%modu)%modu;
      }
    }
  }
  
  return res;
}

int main(){
  int n;
  vll ini{{0, 1}};
  DPM[0] = {{0, 1}, {1, 1}};
  
  while(cin >> n >> modu){
    modu = pow(2, modu);
    vll m;
    deque<int> pot;
    FOR(i, 1, 33) DPM[i] = multM(DPM[i - 1], DPM[i - 1]);
    
    if(n > 1){
      n = n - 1;
      FOR(i, 0, 33) if(n & ((ll)1 << i)) pot.PB(i);
      
      m = DPM[pot.F()];
      pot.P_F();
        
      while(!pot.empty()){
        m = multM(m, DPM[pot.F()]);
        pot.P_F();
      }
      m = multM(ini, m);
      
      cout << m[0][1] << "\n";
    }else cout << ini[0][n] << "\n";
  }

  return 0;
} 