// #include <bits/stdc++.h> // this is not C++; this is a Linuxism
//
// This is the AC solution, but with an artificial O(n^2) loop added.

#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vi> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // needless O(n^2) loop
    int x = 0;
    vi z(n);
    iota(z.begin(), z.end(), 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            z[j] += z[i];
        }
    }
    std::cerr << x << "\n";

    vi dist(n, n + 1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (dist[v] == n + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    cout << dist.back() - 1 << '\n';

    return 0;
}
