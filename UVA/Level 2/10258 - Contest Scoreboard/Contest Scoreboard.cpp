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

struct datos{
  int id, resu, taim;
};

bool compar(datos a, datos b){
  if(a.resu == b.resu){
    if(a.taim == b.taim)
      return a.id < b.id;
    else
      return a.taim < b.taim;
  }else
    return a.resu > b.resu;
}

int main(){
  int cases, pos;
  string ent;
  char judge;
  bool first = true;
  cin >> cases;
  getline(cin, ent);
  getline(cin, ent);
  
  FOR(a, 0, cases){
    vector<pair<int, vector<int> > > parti(101);
    vector<int> b(10), hash(101);
    FOR(i, 1, 101)
      parti[i].second = b;
      
    if(first) first = false;
    else cout << "\n";
    
    while(getline(cin, ent)){
      if(ent.size() == 0) break;
      
      vector<int> aux;
      judge = ent[ent.size() - 1];
      
      FOR(i, 0, 10){
        if(isspace(ent[i])){
          aux.PB(stoi(ent.substr(0, i)));
          hash[aux[0]] = 1;
          pos = i + 1;
          break;
        }
      }
      
      if(judge == 'C' or judge == 'I'){
        FOR(i, pos, ent.size()-1){
          if(isspace(ent[i])){
            aux.PB(stoi(ent.substr(pos, i - pos)));
            pos = i + 1;
          }
        }
        
        if(judge == 'C'){
          if(parti[aux[0]].second[aux[1]] >= 0){
            parti[aux[0]].first += aux[2] + 20*parti[aux[0]].second[aux[1]];
            parti[aux[0]].second[0] += 1;
            parti[aux[0]].second[aux[1]] = -1;
          }
        }else{
          if(parti[aux[0]].second[aux[1]] >= 0)
            parti[aux[0]].second[aux[1]] += 1;
        }
      }
    }
    
    vector<datos> impr;
    
    FOR(i, 1, 101){
      if(hash[i]){
        datos xa;
        xa.id = i, xa.resu = parti[i].second[0], xa.taim = parti[i].first;
        impr.PB(xa);
      }
    }
    
    sort(impr.begin(), impr.end(), compar);
    
    FOR(i, 0, impr.size())
      cout << impr[i].id << " " << impr[i].resu << " " << impr[i].taim << "\n";
  }

  return 0;
}