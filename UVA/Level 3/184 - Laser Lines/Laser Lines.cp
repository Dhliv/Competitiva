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

bool comp(vector<pair<int, int> > &a, vector<pair<int, int> > &b){
  pair<int, int> a1 = a[0], a2 = a[1], b1 = b[0], b2 = b[1];
  
  if(a1 < b1) return true;
  if(a1 == b1){
    if(a2.f < b2.f) return true;
    if(a2.f == b2.f) return (a2.s <= b2.s);
  }
  return false;
}

int main(){
  int x, y, A, B, C, n;
  string a, b, sp = "    ";
  
  while(cin >> x >> y, x + y){
    vector<pair<int, int> > p;
    vector<vector<pair<int, int> > > ans;
    p.PB(MP(x, y));
    set<pair<pair<int, int>, pair<int, int> > > used;
    
    while(cin >> x >> y, x + y) p.PB(MP(x, y));
    
    n = p.size();
    FOR(i, 0, n){
      vector<bool> hash(n);
      FOR(j, i + 1, n){
        if(used.find(MP(p[i], p[j])) != used.end()) continue;
        
        A = p[i].s - p[j].s;
        B = p[j].f - p[i].f;
        C = -(A*p[i].f + B*p[i].s);
        vector<pair<int, int> > aux;
        aux.PB(p[i]);
        aux.PB(p[j]);
        
        FOR(k, j + 1, n){
          if((A*p[k].f + B*p[k].s + C) == 0 and used.find(MP(p[i], p[k])) == used.end() and used.find(MP(p[j], p[k])) == used.end()){
            aux.PB(p[k]);
          }
        }
        
        if(aux.size() > 2){
          FOR(i, 0, aux.size()){
            FOR(j, i + 1, aux.size()) used.insert(MP(aux[i], aux[j]));
          }
          sort(aux.begin(), aux.end());
          ans.PB(aux);
        }
      }
    }
    
    if(ans.size()){
      cout << "The following lines were found:\n";
      sort(ans.begin(), ans.end(), comp);
      
      FOR(i, 0, ans.size()){
        FOR(j, 0, ans[i].size()){
          a = to_string(ans[i][j].f);
          b = to_string(ans[i][j].s);
          if(4 - a.size()) a = sp.substr(0, 4 - a.size()) + a;
          if(4 - b.size()) b = sp.substr(0, 4 - b.size()) + b;
          cout << "(" + a + "," + b + ")";
        }
        cout << "\n";
      }
    }
    else cout << "No lines were found\n";
  }
  
  return 0;
}