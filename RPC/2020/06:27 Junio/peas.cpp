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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main() {
  int res, k, cont = 0, ca;
  string name, ent, peas = "pea soup", pan = "pancakes";
  cin >> res;
  vector<map<string, int> > resta(res);
  vector<string> names(res);
  
  while(res--){
    cin >> k;
    getline(cin, name);
    getline(cin, name);
    names[cont] = name;
    ca = 0;
    while(k--){
      getline(cin, ent);
      if(resta[cont].find(ent) == resta[cont].end())
        resta[cont].insert(MP(ent, ca++));
    }
    cont++;
  }
  
  FOR(i, 0, resta.size()){
    if(resta[i].find(peas) != resta[i].end() and resta[i].find(pan) != resta[i].end()){
      cout << names[i] + "\n";
      return 0;
    }
  }
  
  cout << "Anywhere is fine I guess\n";
  
  return 0;
}