#include <iostream>
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
vector<pii> tree[MAXN];
ll dist[MAXN];

void dfs(int u, int p) {
    for (auto& e : tree[u]) {
        int v, w;
        tie(v, w) = e;

        if (v == p) {
            continue;
        }

        dist[v] = dist[u] + w;
        dfs(v, u);
    }
}

ll solve(int u) {
    dist[u] = 0;
    dfs(u, -1);

    ll ans = 0;
    for (int v = 0; v < n; ++v) {
        ans += (t[u] + t[v]) * dist[v];
    }

    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        tree[u].emplace_back(v, w);
        tree[v].emplace_back(u, w);
    }

    for (int i = 0; i < n; ++i) {
        cout << solve(i) << '\n';
    }

    return 0;
}
