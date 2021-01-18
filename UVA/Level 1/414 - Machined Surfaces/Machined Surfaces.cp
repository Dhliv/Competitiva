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

int main(){
  int n, vacio, mini, cont;
  string ent;
  
  while(cin >> n, n){
    getline(cin, ent);
    mini = INF;
    vacio = 0;
    
    FOR(i, 0, n){
      getline(cin, ent);
      cont = 0;
      
      FOR(j, 0, ent.size()) if(isspace(ent[j]) or ent[j] == 'B') cont++;
      vacio += cont;
      mini = min(mini, cont);
    }
    
    vacio -= mini*n;
    cout << vacio << "\n";
  }
  
  return 0;
}