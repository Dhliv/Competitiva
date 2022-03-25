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

vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
map<string, vector<string> > rest;

bool check(){
  int b, a;
  FOR(i, 0, cows.size()){
    b = i - 1;
    a = i + 1;

    auto it = rest.find(cows[i]);

    if(it != rest.end()){

      if(it->s.size() == 1){
        if(b >= 0 and a < cows.size()){
          if(!(cows[b] == it->s[0] or cows[a] == it->s[0])) return false;
        }else if(b >= 0){
          if(cows[b] != it->s[0]) return false;
        }else{
          if(cows[a] != it->s[0]) return false;
        }
      }else{
        if(b < 0 or a >= cows.size()) return false;
        if(!((cows[b] == it->s[0] and cows[a] == it->s[1]) or (cows[a] == it->s[0] and cows[b] == it->s[1]))) return false;
      }
    }
  }

  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("lineup.in");
  ofstream cout("lineup.out");

  sort(cows.begin(), cows.end());
  int n; cin >> n;
  vector<string> vacio;
  string a, b;
  FOR(i, 0, n){
    cin >> a;
    FOR(j, 0, 5) cin >> b;
    if(!rest.count(b)){
      rest.insert(MP(b, vacio));
    }

    rest[b].PB(a);
  }

  do{
    if(check()){
      FOR(i, 0, cows.size()) cout << cows[i] << "\n";
      break;
    }
  }while(next_permutation(cows.begin(), cows.end()));

  return 0;
}
