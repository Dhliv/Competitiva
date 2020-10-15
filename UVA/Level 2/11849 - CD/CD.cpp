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
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORI(i, a, b) for(int i = a; i >= b; i--)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)

using namespace std;

int main(){
  int n, m, ent, cont;
  
  while(cin >> n >> m, n + m){
    set<int> jack;
    cont = 0;
    
    FOR(i, 0, n){
      cin >> ent;
      jack.insert(ent);
    }
    
    FOR(i, 0, m){
      cin >> ent;
      if(jack.find(ent) != jack.end()) cont++;
    }
    
    cout << cont << "\n";
  }

  return 0;
}
