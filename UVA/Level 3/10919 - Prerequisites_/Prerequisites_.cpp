#include <bits/stdc++.h>
#define INF 1000000000
#define ll long long
#define PB push_back
#define PF push_front
#define P_F pop_front
#define P_B pop_back
#define F front
#define B back
#define MP make_pair
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int cursos, cates, n, auxC;
  
  while(cin >> cursos, cursos){
    cin  >> cates;
    map <int, vector<int> > leMape;
    vector<int> fred(cursos), requi(cates);
    
    FOR(i, 0, cursos)
      cin >> fred[i];
    
    FOR(i, 0, cates){
      cin >> n >> requi[i];
      vector<int> aux(1);
      aux[0] = i;
      
      FOR(j, 0, n){
        cin >> auxC;
        if(leMape.find(auxC) == leMape.end())
          leMape.insert(MP(auxC, aux));
        else
          leMape[auxC].PB(i);
      }
    }
    
    FOR(i, 0, cursos){
      if(leMape.find(fred[i]) != leMape.end()){
        FOR(j, 0, leMape[fred[i]].size()){
          requi[leMape[fred[i]][j]] -= 1;
        }
      }
    }
    
    bool apro = true;
    
    FOR(i, 0, cates){
      if(requi[i] > 0)
        apro = false;
    }
    
    if(apro)
      cout << "yes\n";
    else
      cout << "no\n";
  }

  return 0;
}