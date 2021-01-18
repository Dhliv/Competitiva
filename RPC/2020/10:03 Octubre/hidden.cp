#include <bits/stdc++.h>

using namespace std;

string a, b, c, abc;
int sa, sb, sc, sabc;

long dp[101][101][101];


long f(int i, int j, int k) {
    
    int pos = i + j + k;

    if(pos == sabc) {
        return 1L;
    }

    if(dp[i][j][k] != -1) {
        return dp[i][j][k];
    }

    long long total = 0;
    if(i < sa && abc[pos] == a[i]) {
        total = total + f(i+1, j, k);
    }
    if(j < sb && abc[pos] == b[j]) {
        total = total + f(i, j+1, k);
    }
    if(k < sc && abc[pos] == c[k]) {
        total = total + f(i, j, k+1);
    }

    total = total % 1000000007;

    dp[i][j][k] = total;

    return total;
}

int main() {

    memset(dp, -1, sizeof(dp));

    cin >> a;
    cin >> b;
    cin >> c;
    cin >> abc;

    sa = a.size();
    sb = b.size();
    sc = c.size();
    sabc = abc.size();

    long long res = f(0, 0, 0);

    cout << res << endl;

    return 0;
}
