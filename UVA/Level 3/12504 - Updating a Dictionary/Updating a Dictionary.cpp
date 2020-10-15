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
  int cases, pos;
  string dict, newDict, key, value;
  bool found;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> dict >> newDict;
    map<string, string> leMape, add, chan, elim;
    vector<string> apa, ini;
    pos = 1;
    
    FOR(i, 1, dict.size()){
      if(dict[i] == ':'){
        key = dict.substr(pos, i - pos);
        pos = i+1;
      }
      else if(dict[i] == ',' or (dict[i] == '}' and pos != 1)){
        value = dict.substr(pos, i - pos);
        pos = i+1;
        leMape.insert(MP(key, value));
        ini.PB(key);
      }
    }
    
    //new dictionary
    pos = 1;
    
    FOR(i, 1, newDict.size()){
      if(newDict[i] == ':'){
        key = newDict.substr(pos, i - pos);
        pos = i+1;
      }
      else if(newDict[i] == ',' or (newDict[i] == '}' and pos != 1)){
        value = newDict.substr(pos, i - pos);
        pos = i+1;
        
        if(leMape.find(key) == leMape.end())
          add.insert(MP(key, value));
        else{
          if(value != leMape.find(key)->second)
            chan.insert(MP(key, value));
          apa.PB(key);
        }
      }
    }
    
    if(apa.size() != ini.size()){
      FOR(i, 0, ini.size()){
        found = false;
        FOR(j, 0, apa.size()){
          if(ini[i] == apa[j]){
            found = true;
            break;
          }
        }
        if(!found)
          elim.insert(MP(ini[i], "aaa"));
      }
    }
    
    if(add.size()){
      vector<string> aux;
      forit(x, add)
        aux.PB(x->first);
      
      cout << "+" << aux[0];
        
      FOR(i, 1, add.size())
        cout << "," << aux[i];
      cout << "\n";
    }
    
    if(elim.size()){
      vector<string> aux;
      forit(x, elim)
        aux.PB(x->first);
      
      cout << "-" << aux[0];
        
      FOR(i, 1, elim.size())
        cout << "," << aux[i];
      cout << "\n";
    }
    
    if(chan.size()){
      vector<string> aux;
      forit(x, chan)
        aux.PB(x->first);
      
      cout << "*" << aux[0];
        
      FOR(i, 1, chan.size())
        cout << "," << aux[i];
      cout << "\n";
    }
    
    if(add.size()+chan.size()+elim.size() == 0)
      cout << "No changes\n";
      
    cout << "\n";
  }
  
  return 0;
}