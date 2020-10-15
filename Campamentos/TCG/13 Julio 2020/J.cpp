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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
 int n, d, a, b, l1, l, cont = 0;
 cin >> n >> d >> a >> b;
 vector<pair<int, int> > v(n);
 vector<int> cli;
 
 FOR(i, 0, n){
   cin >> l >> l1;
   v[i] = MP(a*l + l1*b, i + 1);
 }
 
 sort(v.begin(), v.end());
 
 while(d >= v[cont].f and cont < n){
   cli.PB(v[cont].s);
   d -= v[cont].f;
   cont++;
 }
 
 cout << cli.size() << "\n";
 
 FOR(i, 0, cli.size()) cout << cli[i] << " ";
  
  return 0;
}