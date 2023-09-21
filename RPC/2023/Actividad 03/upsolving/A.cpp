#include <bits/stdc++.h>

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

const int INF = 1e9 + 10;

unordered_map<int, unordered_map<int,ll> > pascal;
unordered_map<ll, int> freq;
void init(){
    pascal[0][0] = 1;
    freq[1] = 0;
    for(int i = 1 ; i < 44800 ; ++i){
        pascal[i][0] = 1;

        for(int j = 1 ; j < i ; ++j ){
            int a = pascal[i - 1][j - 1];
            int b = pascal[i - 1][j];
            if(a >= INF || b >= INF ){
                pascal[i][j] = INF;
                break;
            }
            
            pascal[i][j] = a+b;
            if(!freq.count(pascal[i][j])){
                freq[pascal[i][j]] = i;
            }
        }
        pascal[i][i] = 1;
        
    }
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    init();
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        if(freq.count(n)){
            cout << freq[n] + 1 << "\n";
        }else{
            cout << n + 1 << "\n";
        }
    }
    return 0;
}