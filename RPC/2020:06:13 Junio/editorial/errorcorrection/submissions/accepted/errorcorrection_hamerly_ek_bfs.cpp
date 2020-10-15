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

int const SOURCE = 0;
int const SINK = 1;

typedef std::vector<std::vector<int>> Graph;
typedef std::vector<std::map<int, int>> Flow;

void bfs(Flow const &flow, std::vector<int> *path) {
    std::queue<int> frontier{{SOURCE}};

    std::map<int, int> back_links;
    back_links[SOURCE] = -1;

    while (frontier.size() and back_links.find(SINK) == back_links.end()) {
        int current = frontier.front();
        frontier.pop();

        for (auto [neighbor, f] : flow[current]) {
            if ((f == 1) or (back_links.find(neighbor) != back_links.end()))
                continue;
            frontier.push(neighbor);
            back_links[neighbor] = current;
        }
    }

    path->clear();
    if (back_links.find(SINK) != back_links.end()) {
        auto node = SINK;
        while (back_links.find(node) != back_links.end()) {
            path->push_back(node);
            node = back_links[node];
        }

        std::reverse(path->begin(), path->end());
    }
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

    Graph edges(n+2);

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
                        edges[i+2].push_back(si->second+2);
                }
            }
        }
    }

    for (auto i : parity_words[0]) edges[SOURCE].push_back(i+2);
    for (auto i : parity_words[1]) edges[i+2].push_back(SINK);

    Flow flow(n+2);
    for (int i = 0; i < n + 2; ++i)
        for (auto j : edges[i]) {
            flow[i][j] = 0;
            flow[j][i] = 1; // NB: kind of a hack
        }

    std::vector<int> path;
    while (true) {
        bfs(flow, &path);
        if (path.size() == 0)
            break;

        for (size_t i = 1; i < path.size(); ++i) {
            auto a = path[i-1], b = path[i];
            flow[a][b] += 1;
            flow[b][a] -= 1;
        }
    }

    int total_flow = 0;
    for (auto [_, f] : flow[0])
        total_flow += f;
    std::cout << (n - total_flow) << std::endl;

    return 0;
}
