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

bool comp(pair<int, string> a, pair<int, string> b){
  int d1 = a.f, d2 = b.f;
  string s1 = a.s, s2 = b.s;
  
  if(d1 > d2) return true;
  else if(d1 == d2) return (s1 < s2);
  return false;
}

int main(){
  string ent, name;
  int o, cont;
  
  while(getline(cin, ent)){
    if(ent == "0") break;
    map<string, int> reg; //1 encontrado una vez. 2 INVALIDO
    vector<set<string> > act(100);
    vector<pair<int, string> > sh(100);
    name = ent;
    cont = 0;
    sh[0] = MP(0, name);
    
    while(getline(cin, ent)){
      if(ent == "1"){
        for(auto x: act[cont]){
          if(reg.find(x) != reg.end()) reg[x] = 2;
          else reg.insert(MP(x, 1));
        }
        cont++;
        break;
      }
      if(isupper(ent[0])){
        for(auto x: act[cont]){
          if(reg.find(x) != reg.end()) reg[x] = 2;
          else reg.insert(MP(x, 1));
        }
        cont++;
        name = ent;
        sh[cont] = MP(0, name);
      }else act[cont].insert(ent);
    }
    
    FOR(i, 0, cont){
      o = 0;
      for(auto x: act[i]) if(reg[x] == 1) o++;
      sh[i].f = o;
    }
    
    sort(sh.begin(), sh.begin() + cont, comp);
    FOR(i, 0, cont) cout << sh[i].s << " " << sh[i].f << "\n";
  }
  
  return 0;
}