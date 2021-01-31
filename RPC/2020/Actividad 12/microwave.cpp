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
  ll t, h, m, s;
  t = 0;
  string ent, imp = "";
  cin >> ent;
  
  m = stoi(ent.substr(0, 2));
  s = stoi(ent.substr(3, 2));
  
  t = 3600*m;
  t += 60*s;
  t -= s;
  t -= 60*m;
  h = t/3600;
  m = (t%3600)/60;
  s = t%60;
  
  if(h < 10) imp += ("0" + to_string(h) + ":");
  else imp += (to_string(h) + ":");
  
  if(m < 10) imp += ("0" + to_string(m) + ":");
  else imp += (to_string(m) + ":");
  
  if(s < 10) imp += ("0" + to_string(s));
  else imp += to_string(s);
  
  cout << imp << "\n";
  
  return 0;
}