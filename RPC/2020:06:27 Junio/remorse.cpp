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

bool comp(int a, int b){
  return a > b;
}

int main() {
  vector<int> vals{1, 3, 3, 5, 5, 5, 7, 7, 7, 7, 7, 9, 9, 9, 9, 9, 9, 9, 9, 11, 11, 11, 11, 11, 11, 11};
  vector<int> reps(26);
  string ent, axi;
  ll ans = 0, aux = 0;
  
  while(getline(cin, ent)){
    FOR(i, 0, ent.size()){
      if('a' <= ent[i] and ent[i] <= 'z')
        reps[ent[i] - 'a']++;
      else if('A' <= ent[i] and ent[i] <= 'Z')
        reps[ent[i] - 'A']++;
    }
  }
  
  sort(reps.begin(), reps.end(), comp);
  
  FOR(i, 0, 26){
    if(reps[i]){
      aux += reps[i];
    }
  }
  
  ans += 3*(aux - 1);
  
  FOR(i, 0, 26){
    ans += reps[i]*vals[i];
  }
  
  cout << ans << "\n";
  
  return 0;
}