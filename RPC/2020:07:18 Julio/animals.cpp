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
#define FORI(i, a, b) for(int i = a; i >= b; i--)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int n;
  map<char, vector<string> > leMape;
  string name, a, elim;
  bool poss = false;
  cin >> name >> n;

  FOR(i, 0, n){
    cin >> a;
    if(leMape.find(a[0]) == leMape.end()){
      leMape.insert(MP(a[0], vector<string> (1, a)));
    }else{
      leMape[a[0]].PB(a);
    }
  }

  if(leMape.find(name[name.size() - 1]) == leMape.end()){
    cout << "?\n";
  }else{
    vector<string> names;
    names = leMape.find(name[name.size() - 1])->s;
    FOR(i, 0, names.size()){
      elim = names[i];
      if(leMape.find(elim[elim.size() - 1]) == leMape.end()){
        poss = true;
        elim = names[i];
        break;
      }else if(elim[elim.size() - 1] == elim[0] and names.size() == 1){
        poss = true;
        elim = names[i];
        break;
      }
    }

    if(poss) cout << elim + "!\n";
    else cout << names[0] + "\n";
  }
  
  return 0;
}