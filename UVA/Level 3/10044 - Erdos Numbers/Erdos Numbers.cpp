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

void parseIn(string &s){
  string x = "";
  FOR(i, 0, s.size()){
    if(isspace(s[i])) continue;
    if(s[i] == ':') break;
    x.PB(s[i]);
    if(s[i] == ',') x.PB(' ');
  }

  s = x;
  return;
}

void getNames(string &s, deque<string> &nms){
  string x = "";
  bool dos = 0;

  FOR(i, 0, s.size()){
    if(s[i] == ','){
      if(!dos) x.PB(s[i]);
      else{
        nms.PB(x);
        x = "";
        i++;
      }
      dos = 1 - dos;
    }else x.PB(s[i]);
  }

  return;
}

void getIni(string &s, string &ini){
  string x = "";
  FOR(i, 0, s.size()){
    if(s[i] == ',') break;
    x.PB(s[i]);
  }

  if(x == "Erdos") ini = s;
  return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, x, y, t;
  string ax, name, ini;
  cin >> t;

  FOR(ab, 0, t){
    cin >> n >> m;
    deque<string> names, nms;
    map<string, int> id;
    deque<deque<int> > cnx(n);
    getline(cin, ax);
    ini = "";

    FOR(i, 0, n){
      deque<int> cn;

      getline(cin, ax);
      parseIn(ax);
      ax.PB(',');
      getNames(ax, nms);

      while(!nms.empty()){
        name = nms.F();
        nms.P_F();
        if(ini == "") getIni(name, ini);

        auto it = id.find(name);
        if(it == id.end()){
          x = id.size();
          id.insert(MP(name, x));
        }else x = it->s;

        cn.PB(x);
      }

      cnx[i] = cn;
    }

    n = id.size();
    vector<vector<int> > g(n);
    vector<int> s(n, INF), imp(m);

    FOR(i, 0, m){
      getline(cin, ax);
      name = ax;
      parseIn(name);

      auto it = id.find(name);
      if(it == id.end()){
        x = id.size();
        imp[i] = x;
        id.insert(MP(name, x));
      }
      else x = it->s;
      imp[i] = x;
      names.PB(ax);
    }

    FOR(i, 0, cnx.size()){
      FOR(j, 0, cnx[i].size()){
        FOR(k, j + 1, cnx[i].size()){
          x = cnx[i][j];
          y = cnx[i][k];
          g[x].PB(y);
          g[y].PB(x);
        }
      }
    }

    auto it = id.find(ini);
    if(it != id.end()){
      x = it->s;
      deque<int> q;
      q.PB(x);
      s[x] = 0;

      while(!q.empty()){
        x = q.F();
        q.P_F();

        for(int y: g[x]){
          if(s[y] == INF){
            s[y] = s[x] + 1;
            q.PB(y);
          }
        }
      }
    }

    cout << "Scenario " << ab + 1 << "\n";
    FOR(i, 0, m){
      x = imp[i];
      cout << names[i] << " ";
      if(x >= n) cout << "infinity\n";
      else if(s[x] == INF) cout << "infinity\n";
      else cout << s[x] << "\n";
    }
  }

  return 0;
}