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

ll cop = 1000000009;
vector<vll> DPM(67);

vll multM(vll A, vll B){
  vll F(A.size(), vector<ll> (B[0].size()));
  
  FOR(i, 0, A.size()){
    FOR(k, 0, A[0].size()){
      FOR(j, 0, B[0].size()){
        F[i][j] = ((F[i][j])%cop + ((A[i][k])%cop * (B[k][j])%cop)%cop)%cop;
      }
    }
  }
  
  return F;
}

int main(){
  
  ll n, nNew;
  vll ini{{0, 1, 2}}; 
  DPM[0] = {{0, 0, 1}, {1, 0, 1}, {0, 1, 1}};
  FOR(i, 1, 63) DPM[i] = multM(DPM[i - 1], DPM[i - 1]);

  while(cin >> n, n){
    deque<int> nBin;
    vll m;
    
    if(n > 3){
      nNew = n - 3;
      FOR(i, 0, 63) if(nNew & ((long long)1 << i)) nBin.PB(i);

      if(nBin.size() > 1){
        m = multM(DPM[nBin[0]], DPM[nBin[1]]);
        nBin.P_F();
        nBin.P_F();
        
        while(!nBin.empty()){
          m = multM(m, DPM[nBin.F()]);
          nBin.P_F();
        }
        
        m = multM(ini, m);
      }else m = multM(ini, DPM[nBin[0]]);
      
      cout << m[0][2] << "\n";
    }else cout << ini[0][n - 1] << "\n";
  }

  return 0;
} 