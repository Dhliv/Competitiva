#include <iostream>
#include <vector>
#include <tuple>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> taxes(n);
    for (auto &t : taxes) std::cin >> t;
    std::vector<std::vector<std::pair<int, int>>> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--;
        v--;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }

    for (int start = 0; start < n; ++start) {
        unsigned long long answer = 0;
        std::vector<std::tuple<int, int, unsigned long long>> stack = {{start, -1, 0}};

        while (stack.size()) {
            int u, p, v, w;
            unsigned long long depth;
            std::tie(u, p, depth) = stack.back();
            stack.pop_back();

            answer += (taxes[start] + taxes[u]) * depth;

            for (auto vw : tree[u]) {
                std::tie(v, w) = vw;
                if (v == p)
                    continue;
                stack.push_back({v, u, depth + w});
            }
        }

        std::cout << answer << "\n";
    }

    return 0;
}
