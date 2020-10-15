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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int pos, r, d, e, c, t;
  string name, ent, file;
  set<string> val;
  
  val.insert(".py");
  val.insert(".c");
  val.insert(".cpp");
  val.insert(".java");
  
  getline(cin, name);
  getline(cin, ent);
  
  pos = ent.find(name);
  
  if(pos != 0){
    cout << "Compile Error\n";
    return 0;
  }
  
  file = ent.substr(pos + name.size());
  if(val.find(file) == val.end()){
    cout << "Compile Error\n";
    return 0;
  }
  
  cin >> r >> d >> e;
  
  if(r != 0){
    cout << "Run-Time Error\n";
    return 0;
  }
  
  if(e > d){
    cout << "Time Limit Exceeded\n";
    return 0;
  }
  
  cin >> c;
  vector<string> com(c);
  getline(cin, ent);
  
  FOR(i, 0, c) getline(cin, com[i]);
  
  cin >> t;
  getline(cin, ent);
  
  if(t != c){
    cout << "Wrong Answer\n";
    return 0;
  }

  FOR(i, 0, t){
    getline(cin, ent);
    if(com[i] != ent){
      cout << "Wrong Answer\n";
      return 0;
    }
  }
  
  cout << "Correct\n";
  
  return 0;
}