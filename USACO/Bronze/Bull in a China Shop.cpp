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
 
using namespace std;

int n, k;

void moveR(int x, int y, vector<string> &fig, vector<string> &ori){
  FOR(j, y, n){
    FOR(l, x, n){
      fig[j - y][l - x] = ori[j][l];
    }
  }
}

void move(int x, int y, vector<string> &fig, vector<string> &ori){
  FOR(j, 0, n - y){
    FOR(l, 0, n - x){
      fig[j + y][l + x] = ori[j][l];
    }
  }
}

void getAll(vector<vector<string> > &figs, vector<vector<vector<string> > > &allMoves){
  int x, y;
  string relleno = "";
  FOR(i, 0, n) relleno.PB('.');

  FOR(i, 0, k){
    vector<string> aux(n, relleno), ori(n, relleno);
    x = y = n;

    FOR(j, 0, n){
      FOR(l, 0, n){
        if(figs[i][j][l] == '#'){
          y = min(y, (int)j);
          x = min(x, (int)l);
        }
      }
    }

    moveR(x, y, aux, figs[i]);
    figs[i] = aux;

    x = y = 0;
    FOR(j, 0, n){
      FOR(l, 0, n){
        if(figs[i][j][l] == '#'){
          y = max(y, (int)j);
          x = max(x, (int)l);
        }
      }
    }

    x = n - x;
    y = n - y;
    FOR(j, 0, y){
      FOR(l, 0, x){
        aux = ori;
        move(l, j, aux, figs[i]);
        allMoves[i].PB(aux);
      }
    }
  }
}

bool check(vector<string> &a, vector<string> &b, vector<string> &ori){
  vector<string> aux(n);
  FOR(i, 0, n) aux[0].PB(0);
  FOR(i, 1, n) aux[i] = aux[i - 1];

  FOR(i, 0, n){
    FOR(j, 0, n){
      aux[i][j] = (a[i][j] == '#' or b[i][j] == '#') ? '#' : '.';
      if(a[i][j] == '#' and b[i][j] == '#') return false;
      if(aux[i][j] != ori[i][j]) return false;
    }
  }

  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("bcs.in");
  ofstream cout("bcs.out");

  cin >> n >> k;
  vector<string> ori(n);
  vector<vector<string> > figs(k, vector<string> (n));
  vector<vector<vector<string> > > allMoves(k);

  FOR(i, 0, n) cin >> ori[i];

  FOR(i, 0, k){
    FOR(j, 0, n) cin >> figs[i][j];
  }

  getAll(figs, allMoves);
  vector<string> aux(n), cpaux;
  FOR(i, 0, n) aux[0].PB('.');
  FOR(i, 1, n) aux[i] = aux[i - 1];

  FOR(i, 0, k){
    FOR(j, 0, k){
      FOR(l, 0, allMoves[i].size()){
        FOR(m, 0, allMoves[j].size()){
          if(check(allMoves[i][l], allMoves[j][m], ori)){
            cout << i + 1 << " " << j + 1 << "\n";
            return 0;
          }
        }
      }
    }
  }

  return 0;
}
