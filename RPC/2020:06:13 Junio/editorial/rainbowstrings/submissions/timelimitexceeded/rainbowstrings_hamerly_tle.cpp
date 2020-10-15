#include <iostream>
#include <vector>
#include <algorithm>

// DP, probably should be TLE due to the 2^26 factor
// runtime: O(n + 2^k * k^2), where k <= 26 is the number of unique characters

size_t const MOD = 998244353;

int main() {
    std::string s;
    getline(std::cin, s);
    std::vector<int> counts(26, 0);
    for (auto c : s)
        counts[c - 'a']++;
    std::sort(counts.begin(), counts.end(), std::greater<int>());
    while (counts.size() and (counts.back() == 0))
        counts.pop_back();

    std::vector<std::pair<size_t, size_t>> lengths = { {1, 0} };
    std::vector<std::pair<size_t, size_t>> new_lengths;
    size_t total = 1;

    for (size_t length = 1; length <= counts.size(); ++length) {
        new_lengths.clear();
        for (auto x : lengths) {
            for (size_t i = x.second; i < counts.size(); ++i) {
                size_t a = (x.first * counts[i]) % MOD;
                new_lengths.push_back({a, i + 1});
                total = (total + a) % MOD;
            }
        }
        lengths.swap(new_lengths);
    }

    std::cout << total << std::endl;

    return 0;
}

