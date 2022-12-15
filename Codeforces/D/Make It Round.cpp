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
#define PI 3.14159265358979323846

using namespace std;

const ld EPSILON = 0.0000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int dos, cinco, ap2, ap5;
  ll n, m, x, maxi, orin;

  while(t--){
    cin >> n >> m;
    orin = n;
    dos = cinco = ap2 = ap5 = 0;
    maxi = 1;

    while(n%2 == 0){
      dos++;
      n /= 2;
    }

    while(n%5 == 0){
      cinco++;
      n /= 5;
    }

    while(true){
      //cout << dos << " " << cinco << ": " << maxi << endl;
      if(dos + ap2 <= cinco + ap5){
        if(maxi*2 > m) break;
        maxi *= 2;
        ap2++;
      }else{
        if(maxi*5 > m) break;
        maxi *= 5;
        ap5++;
      }
    }

    while(dos + ap2 > cinco + ap5 and ap2){
      ap2--;
      maxi /= 2;
    }

    while(cinco + ap5 > dos + ap2 and ap5){
      ap5--;
      maxi /= 5;
    }

    maxi *= m/maxi;

    cout << maxi*orin << endl;
  }

  return 0;
}