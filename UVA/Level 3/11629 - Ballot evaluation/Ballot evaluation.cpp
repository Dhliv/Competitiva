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

pair<string, int> gn(string ent, int pos){
  int fin = 0;
  string res = "";
  
  FOR(i, pos, ent.size()){
    if(isspace(ent[i])) break;
    fin++;
    res += ent[i];
  }
  
  return MP(res, fin);
}

int main(){
  int g, q;
  ll sum, val;
  double res;
  string name, ent;
  bool valid;
  pair<string, int> p;
  cin >> g >> q;
  map<string, double> m;
  
  FOR(i, 0, g){
    cin >> name >> res;
    m.insert(MP(name, res));
  }
  
  getline(cin, ent);
  FOR(a, 0, q){
    getline(cin, ent);
    sum = 0;
    
    FOR(i, 0, ent.size()){
      if(ent[i] == '<'){
        i++;
        if(ent[i] == '='){
          i += 2;
          p = gn(ent, i);
          res = stod(p.f);
          i += p.s;
          val = res*10;
          if(sum <= val) valid = true;
          else valid = false;
        }else{
          i++;
          p = gn(ent, i);
          res = stod(p.f);
          i += p.s;
          val = res*10;
          if(sum < val) valid = true;
          else valid = false;
        }
        
      }else if(ent[i] == '>'){
        i++;
        if(ent[i] == '='){
          i += 2;
          p = gn(ent, i);
          res = stod(p.f);
          i += p.s;
          val = res*10;
          if(sum >= val) valid = true;
          else valid = false;
        }else{
          i++;
          p = gn(ent, i);
          res = stod(p.f);
          i += p.s;
          val = res*10;
          if(sum > val) valid = true;
          else valid = false;
        }
        
      }else if(ent[i] == '='){
        i += 2;
        p = gn(ent, i);
        res = stod(p.f);
        val = res*10;
        if(sum == val) valid = true;
        else valid = false;
      }else if(!isspace(ent[i]) and ent[i] != '+'){
        p = gn(ent, i);
        i += p.s;
        sum += 10*(m.find(p.f)->s);
      }
    }
    
    if(valid) cout << "Guess #" << a+1 <<  " was correct.\n";
    else cout << "Guess #" << a+1 <<  " was incorrect.\n";
  }
  
  return 0;
}
