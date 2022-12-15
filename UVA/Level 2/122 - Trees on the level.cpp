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
#define PI 3.14159265358979323846

using namespace std;

const ld EPSILON = 0.0000001;

bool able;

struct tr{
  int id;
  bool defined, declared;
  tr *left, *right;

  tr(){
    defined = declared = false;
    left = nullptr;
    right = nullptr;
  }

  void createNode(int i, int &node, string &way){
    if(i == way.size()){
      if(declared) able = false;
      declared = true;
      id = node;
    }else{
      if(!defined){
        defined = true;
        left = new tr();
        right = new tr();
      }

      if(way[i] == 'L') left->createNode(i + 1, node, way);
      else right->createNode(i + 1, node, way);
    }
  }

  void addNode(string &s){
    s[s.size() - 1] = ',';
    string aux = "";
    int n, pos = 0;

    FOR(i, 1, s.size()){
      if(pos){
        if(s[i] == ',') continue;
      }
      else{
        if(s[i] == ','){
          pos = 1;
          n = stoi(aux);
          aux = "";
          continue;
        }
      }

      aux.PB(s[i]);
    }

    createNode(0, n, aux);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  while(cin >> s){
    tr *t = new tr(), *taux;
    able = true;
    t->addNode(s);

    while(true){
      cin >> s;
      if(s == "()") break;

      t->addNode(s);
    }

    deque<tr*> q, next;
    deque<int> ans;
    q.PB(t);

    while(!q.empty() and able){
      while(!q.empty() and able){
        taux = q.F(); q.P_F();
        if(!taux->declared){
          able = false;
          break;
        }

        ans.PB(taux->id);
        if(!taux->defined) continue;
        if(taux->left->declared) next.PB(taux->left);
        if(taux->right->declared) next.PB(taux->right);
      }

      q.swap(next);
    }

    if(able){
      cout << ans.F();
      FOR(i, 1, ans.size()) cout << " " << ans[i];
      cout << "\n";
    }else cout << "not complete\n";
  }

  return 0;
}