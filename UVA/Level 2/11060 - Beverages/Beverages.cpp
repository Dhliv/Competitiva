#include <bits/stdc++.h>
#define LINF LLONG_MAX
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
#define FORI(i, a, b) for(int i = a; i >= b; i--)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int n, m, x, y, cont = 1;
  string name, ori, dest;
  
  while(cin >> n){
    
    map<string, int> names;
    vector<string> nodos(n);
    vector<vector<int> > grafo(n);
    vector<int> veces(n, 0);
    
    FOR(i, 0, n){
      cin >> name;
      nodos[i] = name;
      names.insert(MP(name, i));
    }
    
    cin >> m;
    
    FOR(i, 0, m){
      cin >> ori >> dest;
      x = names.find(ori)->s, y = names.find(dest)->s;
      grafo[x].PB(y);
      veces[y]++;
    }
    
    deque<int> d;
    priority_queue<int> conex;
    
    FOR(i, 0, n){
      if(veces[i] == 0) conex.push(-i);
    }
    
    while(!conex.empty()){
      x = -conex.top();
      conex.pop();
      d.PB(x);
      
      FOR(i, 0, grafo[x].size()){
        y = grafo[x][i];
        veces[y]--;
        if(veces[y] == 0) conex.push(-y);
      }
    }
    
    cout << "Case #" << cont++ << ": Dilbert should drink beverages in this order:";
    
    while(!d.empty()){
      name = nodos[d.F()];
      d.P_F();
      cout << " " + name;
    }
    
    cout << ".\n\n";
  }
  
  return 0;
}