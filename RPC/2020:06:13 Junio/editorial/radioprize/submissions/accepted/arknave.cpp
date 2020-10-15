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

int depth[MAXN];
int sz[MAXN];
ll tsum[MAXN];
ll ans[MAXN];

void dfs1(int u, int p) {
    sz[u] = 1;
    tsum[u] = t[u];
    for (auto& e : tree[u]) {
        int v, w;
        tie(v, w) = e;

        if (v == p) continue;

        depth[v] = depth[u] + w;

        dfs1(v, u);

        sz[u] += sz[v];
        tsum[u] += tsum[v];
    }
}

void dfs2(int u, int p, ll depth_sum, ll tax_depth_sum) {
    ans[u] = t[u] * depth_sum + tax_depth_sum;
    for (auto& e : tree[u]) {
        int v, w;
        tie(v, w) = e;
        if (v == p) continue;

        dfs2(
            v,
            u,
            depth_sum + w * (n - 2 * sz[v]),
            tax_depth_sum + w * (tsum[0] - 2 * tsum[v])
        );
    }
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

    dfs1(0, -1);
    ll depth_sum = 0;
    ll tax_depth_sum = 0;
    for (int i = 0; i < n; ++i) {
        depth_sum += depth[i];
        tax_depth_sum += 1LL * t[i] * depth[i];
    }

    dfs2(0, -1, depth_sum, tax_depth_sum);

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}
