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
#define MAX 3010
 
using namespace std;

int dp[MAX*2][MAX*2];
int D[MAX*2][MAX*2];
int n, m, x, y, x0, yO, k, q, nx;

void f(){
	FOR(i, 0, nx){
		FOR(j, 0, nx){
			dp[i][j] = D[i][j];
			if(i) dp[i][j] += dp[i - 1][j];
			if(j) dp[i][j] += dp[i][j - 1];
			if(i and j) dp[i][j] -= dp[i - 1][j - 1];
		}
	}
}

int calc(int i, int j, int L){
	int ax = 0;
	int x = x0 + i - j;
	int y = yO + i + j;
	int nX, nY;

	nX = min(nx - 1, x + L);
	nY = min(nx - 1, y + L);

	//cout << "(" << x << ", " << y << ") ";
	//cout << "(" << nX << ", " << nY << ") ";

	ax = dp[nX][nY];
	if(x - L - 1 >= 0) ax -= dp[x - L - 1][nY];
	if(y - L - 1 >= 0) ax -= dp[nX][y - L - 1];
	if(x - L - 1 >= 0 and y - L - 1 >= 0) ax += dp[x - L - 1][y - L - 1];

	return ax;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int L, id = 1;

	while(cin >> m >> n >> k >> q, n + m + k + q){
		cout << "Case " << id++ << ":\n";

		nx = n + m - 1;
		x0 = m - 1;
		yO = 0;
		FOR(i, 0, nx){
			FOR(j, 0, nx) D[i][j] = 0;
		}

		FOR(i, 0, k){
			cin >> y >> x;
			x--; y--;
			D[x0 + x - y][yO + x + y] = 1;
		}

		f();

		int maxi = -1, posx = INF, posy = INF, ans;

		FOR(i, 0, q){
			cin >> L;
			maxi = -1; posx = INF; posy = INF;

			FOR(i, 0, n){
				FOR(j, 0, m){
					//cout << i << " " << j << ": ";
					ans = calc(i, j, L);
					//cout << ans << "\n";

					if(ans > maxi){
						posx = i;
						posy = j;
						maxi = ans;
					}
				}
			}

			cout << maxi << " (" << posy + 1  << "," << posx + 1 << ")\n";
		}
	}
	
	return 0;
}