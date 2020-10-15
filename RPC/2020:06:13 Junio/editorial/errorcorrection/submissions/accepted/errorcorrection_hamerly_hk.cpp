#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <cassert>

int parity(std::string const &s) {
    bool p = false;
    for (auto i = s.begin(); i != s.end(); ++i)
        for (auto j = i + 1; j != s.end(); ++j)
            if (*j < *i)
                p = !p;
    return (int)p;
}

std::string swap(std::string const &s, size_t i, size_t j) {
    std::string w(s);
    w[i] = s[j];
    w[j] = s[i];
    return w;
}

int const SINK = -1;
int const oo = 10000000;

typedef std::vector<std::vector<int>> Graph;

bool bfs(Graph const &edges, std::map<int, int> const &fwd, std::map<int, int> const &back, std::map<int, int> &dist) {
    std::queue<int> frontier;

    for (auto [u, v] : fwd) {
        if (v == -1) {
            dist[u] = 0;
            frontier.push(u);
        } else {
            dist[u] = oo;
        }
    }

    dist[SINK] = oo;

    while (frontier.size()) {
        int u = frontier.front();
        frontier.pop();

        if (dist[u] < dist[SINK]) {
            for (auto v : edges[u]) {
                auto bv = back.find(v);
                assert(bv != back.end());
                if (dist[bv->second] == oo) {
                    dist[bv->second] = dist[u] + 1;
                    frontier.push(bv->second);
                }
            }
        }
    }

    return dist[SINK] != oo;
}

bool dfs(Graph const &edges, int u, std::map<int, int> *fwd, std::map<int, int> *back, std::map<int, int> const &dist) {
    if (u == SINK)
        return true;

    for (auto v : edges[u]) {
        if (dist.find((*back)[v])->second == dist.find(u)->second + 1) {
            if (dfs(edges, (*back)[v], fwd, back, dist)) {
                (*fwd)[u] = v;
                (*back)[v] = u;
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> words(n);
    std::unordered_map<std::string, size_t> word_index;
    for (int i = 0; i < n; ++i) {
        std::cin >> words[i];
        word_index[words[i]] = i;
    }

    Graph edges(n);

    std::vector<std::vector<int>> parity_words(2);

    size_t k = words[0].size();
    for (int i = 0; i < n; ++i) {
        int p = parity(words[i]);
        parity_words[p].push_back(i);

        if (p == 0) {
            for (size_t a = 0; a < k; ++a) {
                for (size_t b = a + 1; b < k; ++b) {
                    auto s = swap(words[i], a, b);
                    auto si = word_index.find(s);
                    if (si != word_index.end())
                        edges[i].push_back(si->second);
                }
            }
        }
    }

    std::map<int, int> fwd, back, dist;

    for (auto u : parity_words[0]) fwd[u] = -1;
    for (auto v : parity_words[1]) back[v] = -1;
    for (int u = 0; u < n; ++u) dist[u] = oo;

    while (bfs(edges, fwd, back, dist)) {
        for (auto [u, v] : fwd) {
            if (v == -1)
                dfs(edges, u, &fwd, &back, dist);
        }
    }

    int total_flow = 0;
    for (auto [u, v] : fwd)
        total_flow += (v != -1);
    std::cout << (n - total_flow) << std::endl;

    return 0;
}

