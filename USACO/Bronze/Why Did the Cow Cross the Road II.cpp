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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("circlecross.in");
  ofstream cout("circlecross.out");

  string s; cin >> s;
  set<pair<char, char> > pares;
  set<char> letras;
  char a, b;
  int pos;

  FOR(i, 0, s.size()){
    a = s[i];
    letras.clear();

    // linear
    FOR(j, 1, s.size()){
      b = s[(j + i)%s.size()];

      if(b == a){
        pos = (j + i)%s.size();
        break;
      }

      if(letras.count(b)) letras.erase(b);
      else letras.insert(b);
    }

    for(auto c: letras){
      if(a < c) pares.insert(MP(a, c));
      else pares.insert(MP(c, a));
    }
    letras.clear();

    // circular
    FOR(j, 1, s.size()){
      b = s[(j + pos)%s.size()];

      if(b == a){
        pos = (j + i)%s.size();
        break;
      }

      if(letras.count(b)) letras.erase(b);
      else letras.insert(b);
    }

    for(auto c: letras){
      if(a < c) pares.insert(MP(a, c));
      else pares.insert(MP(c, a));
    }
  }

  cout << pares.size() << "\n";

  return 0;
}
