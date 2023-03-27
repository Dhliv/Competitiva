#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_mini
#define ll long long
#define ull unsigned long long
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
#define PI 3.14159265358979323846

using namespace std;
 
const ld EPSILON = 0.0000001;

int hsh[255];
bool able;
int n;
string s;

void f(int i, int last){
  if(able) return;
  if(i > n){
    able = true;
    return;
  }

  if(hsh[s[i]] == -1){
    hsh[s[i]] = 1 - last;
    f(i + 1, 1 - last);
  }else{
    if(hsh[s[i]] == last) return;
    f(i + 1, 1 - last);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;

  while(t--){
    cin >> n >> s;
    memset(hsh, -1, sizeof(hsh));

    able = false;
    f(0, 0);
    f(0, 1);

    cout << (able ? "YES" : "NO") << "\n";
  }
 
  return 0;
}