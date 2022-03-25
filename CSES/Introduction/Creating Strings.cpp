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

int n;
bool choosed[10] = {0};
string per = "";
set<string> words;

void printAll(vector<char> &p){
  if(per.size() == n){
    words.insert(per);
    return;
  }

  FOR(i, 0, n){
    if(choosed[i]) continue;
    choosed[i] = 1;
    per.PB(p[i]);
    printAll(p);
    per.P_B();
    choosed[i] = 0;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string a; cin >> a;
  n = a.size();
  vector<char> p(n);
  FOR(i, 0, n) p[i] = a[i];
  sort(p.begin(), p.end());

  printAll(p);
  cout << words.size() << "\n";

  for(auto word: words){
    cout << word << "\n";
  }

  return 0;
}
