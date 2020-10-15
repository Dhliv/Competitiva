// #include <bits/stdc++.h> // this is not C++; this is a Linuxism
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
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
