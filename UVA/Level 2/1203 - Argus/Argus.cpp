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
  string bas;
  int id, per, k;
  pair<int, int> a;
  vector<int> ids(3010);
  priority_queue<pair<int, int> > p;
  
  while(cin >> bas, bas != "#"){
    cin >> id >> per;
    ids[id] = per;
    p.push(MP(-per, -id));
  }
  
  cin >> k;
  
  
  FOR(i, 0, k){
    a = p.top();
    id = a.s;
    p.pop();
    cout << -id << "\n";
    p.push(MP(a.f - ids[-id], id));
  }

  return 0;
}
