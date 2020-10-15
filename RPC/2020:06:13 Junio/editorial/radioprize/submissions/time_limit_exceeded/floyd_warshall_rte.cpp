// lol this should never come close to working
#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr int MAXN = 100000;
int n;
int t[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    // this won't compile if it's allocated on the stack
    const ll INF = 1e18;
    vector<vector<ll>> adj(n, vector<ll>(n, INF));
    for (int i = 0; i < n; ++i) {
        adj[i][i] = 0;
    }

    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        adj[u][v] = adj[v][u] = w;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    cout << fixed << setprecision(10);
    for (int i = 0; i < n; ++i) {
        ll res = 0;
        for (int j = 0; j < n; ++j) {
            res += (t[i] + t[j]) * adj[i][j];
        }

        cout << res << '\n';
    }

    return 0;
}
