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

pair<int, int> getnumber(string &ent, int pos){
  string num = "";
  int fin = 0;
  
  FOR(i, pos, ent.size()){
    if(isspace(ent[i])) break;
    num += ent[i];
    fin++;
  }
  
  return MP(stoi(num), fin);
}

int main(){
  string ent;
  pair<int, int> p;
  int a;
  bool valid;
  
  while(getline(cin, ent)){
    deque<pair<int, ll> > pila;
    valid = true;
    
    FOR(i, 0, ent.size()){
      if(ent[i] == '-'){
        i++;
        p = getnumber(ent, i);
        pila.PB(MP(p.f, 0));
        i += p.s;
      }else if(!isspace(ent[i])){
        p = getnumber(ent, i);
        if(pila.empty()) valid = false;
        else if(pila.B().f != p.f) valid = false;
        else{
          if(pila.B().s >= pila.B().f) valid = false;
          a = pila.B().f;
          pila.P_B();
          if(!pila.empty()) pila.B().s += a;
        }
        i += p.s;
      }
    }
    
    if(valid and pila.empty()) cout << ":-) Matrioshka!\n";
    else cout << ":-( Try again.\n";
  }
  
  return 0;
}
