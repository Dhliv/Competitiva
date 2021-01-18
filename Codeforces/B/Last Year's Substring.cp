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

int main(){
  int n, cases;
  string ent;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> n >> ent;
    
    if(ent.substr(0, 4) == "2020" or ent.substr(n - 4, 4) == "2020") cout << "YES\n";
    else if(ent.substr(0, 1) == "2" and ent.substr(n - 3, 3) == "020") cout << "YES\n";
    else if(ent.substr(0, 2) == ent.substr(n - 2, 2) and ent.substr(0, 2) == "20") cout << "YES\n";
    else if(ent.substr(0, 3) == "202" and ent.substr(n - 1, 1) == "0") cout << "YES\n";
    else cout << "NO\n";
  }
  
  return 0;
}