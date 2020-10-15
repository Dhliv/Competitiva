#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

// O(n log n)

struct Star {
    double t, s, a;
    double low() const { return a - t/s; }
    double high() const { return a + t/s; }
};

int const ENTER = 0;
int const MIDDLE = 1;
int const LEAVE = 2;

struct Event {
    double angle;
    int index;
    int kind;
    bool operator<(Event const &e) const { return angle < e.angle; }
};

int main() {
    int n;
    std::cin >> n;
    std::vector<Star> stars(n);
    for (Star &star : stars)
        std::cin >> star.t >> star.s >> star.a;

    std::vector<Event> events(3 * n);
    for (int i = 0; i < n; ++i) {
        events[i * 3 + 0] = {stars[i].low(),  i, ENTER};
        events[i * 3 + 1] = {stars[i].a,      i, MIDDLE};
        events[i * 3 + 2] = {stars[i].high(), i, LEAVE};
    }
    std::sort(events.begin(), events.end());

    long double sum_t = 0,
           sum_sa = 0,
           sum_s = 0;
    long double best_distance = 0.0;

    for (Event const &e : events) {
        Star const &star = stars[e.index];
        long double sa = star.s * star.a;
        long double distance = 0.0;
        if (e.kind == ENTER) {
            sum_t += star.t;
            sum_sa -= sa;
            sum_s += star.s;
            distance = sum_t + sum_sa + e.angle * sum_s;
        } else if (e.kind == MIDDLE) {
            sum_sa += sa;
            sum_s -= star.s;
            distance = sum_t + sum_sa + e.angle * sum_s;
            sum_sa += sa;
            sum_s -= star.s;
        } else if (e.kind == LEAVE) {
            sum_t -= star.t;
            sum_sa -= sa;
            sum_s += star.s;
            distance = sum_t + sum_sa + e.angle * sum_s;
        }

        best_distance = std::max(distance, best_distance);
    }

    std::cout << std::setprecision(10) << std::fixed << best_distance << std::endl;

    return 0;
}

