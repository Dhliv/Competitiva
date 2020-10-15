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
  string name, aux;
  int requi, pro, reAux, cont = 1, c = 0;
  double precio, best;
  
  while(cin >> requi >> pro, pro+requi){
    if(c)
      cout << "\n";
    else
      c++;
      
    cout << "RFP #" << cont++ << "\n";
      
    vector<string> orden(pro);
    vector< pair<double, string> > winners;
    map <string, int> leMape;
    vector< pair<double, pair<double, string> > > impor(pro);
    getline(cin, aux);
    
    FOR(i, 0, requi)
      getline(cin, aux);
      
    FOR(i, 0, pro){
      getline(cin, orden[i]);
      cin >> precio >> reAux;
      impor[i] = MP((1.0 * reAux)/(requi * 1.0), MP(precio, orden[i]));
      getline(cin, aux);
      
      FOR(j, 0, reAux)
        getline(cin, aux);
    }
    
    sort(impor.begin(), impor.end());
    
    best = impor[pro-1].first;
    
    for(int i = pro-1; i >= 0; i--){
      if(impor[i].first == best)
        winners.PB(MP(impor[i].second.first, impor[i].second.second));
      else
        break;
    }
    
    if(winners.size() == 1)
      cout << winners[0].second << "\n";
    else{
      sort(winners.begin(), winners.end());
      best = winners[0].first;
      
      FOR(i, 0, winners.size()){
        if(winners[i].first == best)
          leMape.insert(MP(winners[i].second, 0));
        else
          break;
      }
      
      FOR(i, 0, pro){
        if(leMape.find(orden[i]) != leMape.end()){
          cout << orden[i] << "\n";
          break;
        }
      }
    }
  }
  
  return 0;
}