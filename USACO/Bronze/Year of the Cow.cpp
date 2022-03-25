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

map<string, pair<string, int> > p;
vector<string> years{"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};

void calc(string &ca, string &cb, string &t, string &year){
  string year2 = p.find(ca)->s.f;

  int sum = 0, mult, posa, posb;

  FOR(i, 0, years.size()){
    if(years[i] == year) posb = i;
    if(years[i] == year2) posa = i;
  }

  if(t == "next"){
    mult = 1;
    if(posb > posa) sum = posb - posa;
    else sum = years.size() - posa + posb;
  }else{
    mult = -1;
    if(posb < posa) sum = posa - posb;
    else sum = years.size() - posb + posa;
  }

  sum = p[ca].s + sum*mult;
  p.insert(MP(cb, MP(year, sum)));
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n; cin >> n;
  string ca, cb, t, year;
  p.insert(MP("Bessie", MP("Ox", 100000)));

  FOR(i, 0, n){
    cin >> ca;
    cin >> t >> t >> t;
    cin >> year;
    cin >> cb >> cb >> cb;
    calc(cb, ca, t, year);
  }

  cout << abs(p["Bessie"].s - p["Elsie"].s) << "\n";

  return 0;
}
