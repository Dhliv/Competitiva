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
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int cases, pagas, val, lines;
  double costo;
  string ent;
  wchar_t k;
  
  cin >> cases;
  
  cout.precision(2);
  
  FOR(a, 0, cases){
    cin >> pagas;
    int hash[130] = {0};
    costo = 0;
    getline(cin, ent);
    
    FOR(i, 0, pagas){
      getline(cin, ent);
      k = ent[0];
      val = stoi(ent.substr(2, ent.size() - 2));
      
      hash[k] = val;
    }
    
    cin >> lines;
    getline(cin, ent);
    
    FOR(i, 0, lines){
      getline(cin, ent);
      FOR(j, 0, ent.size()){
        if(ent[j] >= 32 and ent[j] <= 126 and hash[ent[j]])
          costo += hash[ent[j]];
      }
    }
    
    cout << fixed << costo/100 << "$\n";
  }
  
  return 0;
}