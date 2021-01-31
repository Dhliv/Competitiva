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
#define MP make_pair
#define For(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  ll N, M, a, b, nodo;
  cin >> N >> M;
  vector< vector<int> > conex(N+1);
  vector<int> minimos(N+1, INF);

  For(i, 0, M){
    cin >> a >> b;
    conex[a].PB(b);
    conex[b].PB(a);
  }

  deque<int> dq;
  dq.PB(1);
  minimos[1] = 0;

  while(!dq.empty()){
    nodo = dq.F();
    //if(nodo == N) break;
    dq.P_F();

    For(i, 0, conex[nodo].size()){
      if(minimos[conex[nodo][i]] == INF){
        minimos[conex[nodo][i]] = minimos[nodo] + 1;
        dq.PB(conex[nodo][i]);
      }
    }
  }

  cout << minimos[N] - 1 << "\n";

  return 0;
}