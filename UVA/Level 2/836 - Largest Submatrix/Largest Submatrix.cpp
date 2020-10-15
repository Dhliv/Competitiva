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

int izq(vector<int> datos){
  ll res = 0, min, n = datos.size();
  
  FOR(i, 0, n){
    min = *min_element(datos.begin() + i, datos.end());
    res = max(res, min*(n - i));
  }
  
  return res;
}

int der(vector<int> datos){
  ll res = 0, mini, n = datos.size();
  
  FORI(i, n - 1, 0){
    mini = *min_element(datos.rbegin() + (n - (i + 1)), datos.rend());
    res = max(res, mini*(i + 1));
  }
  
  return res;
}

int minimo(vector<int> datos, int ini, int fin){
  int mini = INF;
  
  FOR(i, ini, fin + 1){
    mini = min(mini, datos[i]);
  }
  
  return mini;
}

int punteros(vector<int> datos){
  ll res = 0, mini, n = datos.size();
  int left = 0, right = n - 1;
  bool l = true, r = true;
  
  //left first
  while(left != right){
    if(l){
      l = false;
      left++;
    }else{
      l = true;
      right--;
    }
    mini = minimo(datos, left, right);
    res = max(res, mini*(right - (left - 1)));
  }
  
  left = 0, right = n - 1;
  
  //right first
  while(left != right){
    if(r){
      r = false;
      right--;
    }else{
      r = true;
      left++;
    }
    mini = minimo(datos, left, right);
    res = max(res, mini*(right - (left - 1)));
  }
  
  return res;
}

int down(vector<string> &m, int i, int j){
  if(i >= m.size()) return 0;
  else if(m[i][j] == '0') return 0;
  else return 1 + down(m, i + 1, j);
}

int main(){
  int cases, n, grups, ans, x, y, z;
  string ent;
  bool para;
  cin >> cases;
  getline(cin, ent);
  getline(cin, ent);
  
  FOR(a, 0, cases){
    if(a) cout << "\n";
    
    vector<string> m;
    ans = 0;
    
    while(getline(cin, ent), ent.size()) m.PB(ent);
    
    n = m.size();
    deque<vector<int> > cas(n);
    
    FOR(i, 0, n){
      vector<int> aux;
      FOR(j, 0, n) if(m[i][j] == '1') aux.PB(j);
      cas[i] = aux;
    }
    
    vector<vector<vector<int> > > alcances(n, vector<vector<int> > (n));
    
    FOR(i, 0, n){
      grups = 0;
      if(cas[i].size()) alcances[i][grups].PB(cas[i][0]);
      FOR(j, 1, cas[i].size()){
        if(cas[i][j] != 1 + cas[i][j - 1]) grups++;
        alcances[i][grups].PB(cas[i][j]);
      }
    }
    
    FOR(i, 0, n){
      FOR(j, 0, n){
        if(alcances[i][j].empty()) break;
        else{
          FOR(k, 0, alcances[i][j].size()){
            alcances[i][j][k] = down(m, i, alcances[i][j][k]);
          }
        }
      }
    }
    
    FOR(i, 0, n){
      FOR(j, 0, n){
        if(alcances[i][j].empty()) break;
        else{
          //existe grupo
          if(alcances[i][j].size() == 1){ 
            if(alcances[i][j][0] > ans) ans = alcances[i][j][0];
          }
          else{
            x = izq(alcances[i][j]);
            y = der(alcances[i][j]);
            z = punteros(alcances[i][j]);
            ans = max(ans, max(x, max(y, z)));
          }
        }
      }
    }
    
    cout << ans << "\n";
  }
  
  return 0;
}
