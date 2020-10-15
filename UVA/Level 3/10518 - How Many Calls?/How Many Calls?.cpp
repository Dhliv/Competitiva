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

vector<vll> DPM(65);
ll modu;

vll multM(vll A, vll B){
  vll F(A.size(), vector<ll> (B[0].size()));
  
  FOR(i, 0, A.size()){
    FOR(k, 0, B.size()){
      FOR(j, 0, B[0].size()){
        F[i][j] = ((F[i][j])%modu + ((A[i][k])%modu * (B[k][j])%modu)%modu)%modu;
      }
    }
  }
  
  return F;
}

int main(){
  ll n, aux, g = 1;
  vll ini{{1, 1}};
  DPM[0] = {{0, 1}, {1, 1}};
  
  while(cin >> n >> modu, n + modu){
    vll m;
    deque<int> pot;
    aux = 0;
    cout << "Case " << g++ << ": " << n << " " << modu << " ";
    
    if(n > 1){
      FOR(i, 1, 64) DPM[i] = multM(DPM[i - 1], DPM[i - 1]);
      
      FOR(i, 0, 64) if(n & ((ll)1 << i)) pot.PB(i);
      
      m = DPM[pot.F()];
      pot.P_F();
      
      while(!pot.empty()){
        m = multM(m, DPM[pot.F()]);
        pot.P_F();
      }
      
      m = multM(ini, m);
      
      if(m[0][0] != 0) aux = ((m[0][0] * 2) - 1)%modu;
      else aux = modu - 1;
      
      cout << aux << "\n";
    }else cout << 1%modu << "\n";
  }
  
  return 0;
}
