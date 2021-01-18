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

vector<int> data;

int find(int x){
  if(data[x] == x) return x;
  return data[x] = find(data[x]);
}

void com(int a, int b){
  int fa = find(a), fb = find(b);
  data[fa] = fb;
  return;
}

int main(){
  int cases, n, pos, cont, x, y, A, W;
  string ent;
  cin >> cases;
  
  FOR(ab, 0, cases){
    if(ab) cout << "\n";
    cin >> n;
    vector<int> q(2);
    data.resize(n + 1);
    FOR(i, 1, n + 1) data[i] = i;
    A = W = 0;
    
    getline(cin, ent);
    while(getline(cin, ent)){
      if(ent.size() == 0) break;
      ent += " ";
      
      pos = 2;
      cont = 0;
      FOR(i, 3, ent.size()){
        if(isspace(ent[i])){
          q[cont++] = stoi(ent.substr(pos, i - pos));
          pos = i + 1;
        }
      }
      
      if(ent[0] == 'c') com(q[0], q[1]);
      else{
        x = find(q[0]), y = find(q[1]);
        if(x == y) A++;
        else W++;
      }
    }
    
    cout << A << "," << W << "\n";
  }
  
  return 0;
}