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

set<int> fi, se, ans;
int act = 1000;
int qfi[101] = {0}, qse[101] = {0};

void getAll(int day){
  if(day == 5){
    ans.insert(act);
    return;
  }

  if(day & 1){ // quito de fi y llevo a se.
    for(auto bucket: fi){
      if(qfi[bucket] == 0) continue;
      act -= bucket;
      qfi[bucket]--;
      qse[bucket]++;
      getAll(day + 1);
      act += bucket;
      qfi[bucket]++;
      qse[bucket]--;
    }
  }else{  // quito de se y llevo a fi.
    for(auto bucket: se){
      if(qse[bucket] == 0) continue;
      act += bucket;
      qse[bucket]--;
      qfi[bucket]++;
      getAll(day + 1);
      act -= bucket;
      qse[bucket]++;
      qfi[bucket]--;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("backforth.in");
  ofstream cout("backforth.out");

  int x;
  FOR(i, 0, 10){
    cin >> x;
    fi.insert(x);
    se.insert(x);
    qfi[x]++;
  }

  FOR(i, 0, 10){
    cin >> x;
    fi.insert(x);
    se.insert(x);
    qse[x]++;
  }

  getAll(1);
  cout << ans.size() << "\n";

  return 0;
}
