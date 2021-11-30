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

int ttl(pair<int, int> &a){
  return a.f + a.s;
}

bool comp(pair<int, int> &a, pair<int, int> &b){
  int s1 = ttl(a), s2 = ttl(b);

  if(s1 == s2){
    return a.f < b.f;
  }
  return s1 < s2;
}
  
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, x, y; cin >> n;
  vector<pair<int, int> > p(n);
  pair<int, int> a, b;
  ll A, B, total;
  A = B = 0;

  FOR(i, 0, n){
    cin >> x >> y;
    p[i] = MP(x, y);
    A += x;
    B += y;
  }

  if(n % 2 != 0 || 2*A % n != 0 || 2*B % n != 0){
    cout << "impossible\n";
    return 0;
  }

  A= 2*A/n;
  B = 2*B/n;
  total = A+B;

  sort(p.begin(), p.end(), comp);

  for(int i = 0 ; i < n/2 ; ++i){
    a = p[i];
    b = p[n - i - 1];

    if(ttl(a) + ttl(b) == total){
        if(a.f + b.f != A){
            cout << "impossible\n";
            return 0;
        }
    }else{
      cout << "impossible\n";
      return 0;
    }
  }

  cout << "possible\n";
  
  return 0;
}