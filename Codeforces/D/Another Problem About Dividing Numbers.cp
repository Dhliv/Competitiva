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
#define MAX 31630

using namespace std;

int np;
deque<int> prs;
vector<bool> pr(MAX);

void lookP(int &n){
  for(int i = 0; i < prs.size() and n > 1; i++){
    while(n % prs[i] == 0){
      np++;
      n /= prs[i];
    }
  }
  if(n > 1) np++;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  FOR(i, 2, MAX){
    if(!pr[i]){
      prs.PB(i);
      for(int j = i + i; j < MAX; j += i) pr[j] = 1;
    }
  }
  
  int a, b, t, k;
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> a >> b >> k;
    if(a > b) swap(a, b);
    
    if(k >= 60) cout << "NO\n";
    else if(k == 1){
      
      if(__gcd(a, b) == a and a != b) cout << "YES\n";
      else cout << "NO\n";
    }else{
      np = 0;
      lookP(a);
      lookP(b);
      
      if(k <= np) cout << "YES\n";
      else cout << "NO\n";
    }
  }

  return 0;
}