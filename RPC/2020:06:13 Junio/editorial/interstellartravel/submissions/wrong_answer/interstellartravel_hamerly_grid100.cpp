#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

// depending on the size of the input and the smoothness of the space, this
// could be categorized as TLE or WA (or possibly AC)

struct Star {
    double t, s, a;
    double low() const { return a - t/s; }
    double high() const { return a + t/s; }
};

double get_angle(double low, double high, int i, int grid_division) {
    return (high - low) * (i + 0.5) / grid_division + low;
}

long double value(std::vector<Star> const &stars, double angle) {
    long double v = 0.0;
    for (Star const &star : stars) {
	  double delta = fabs(star.a - angle);
	  if (delta > M_PI)
		delta = 2.0*M_PI - delta;
        long double sv = star.t - star.s * delta;
        v += std::max((long double)0.0, sv);
    }
    return v;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Star> stars(n);
    for (Star &star : stars)
        std::cin >> star.t >> star.s >> star.a;

    int grid_division = 100;
    int search_arity = 5;

    double low = 0.0;
    double high = M_PI * 2;
    double eps = 1e-8;

    while (low + eps <= high) {
        int best_i = 0;
        long double best_v = value(stars, get_angle(low, high, 0, grid_division));

        for (int i = 1; i <= grid_division; ++i) {
            long double v = value(stars, get_angle(low, high, i, grid_division));
            if (best_v < v) {
                best_v = v;
                best_i = i;
            }
        }

        double new_mid = get_angle(low, high, best_i, grid_division);
        double new_low = std::max(0.0, new_mid - (high - low) / search_arity);
        double new_high = std::min(2 * M_PI, new_mid + (high - low) / search_arity);
        low = new_low;
        high = new_high;
    }

    std::cout << std::setprecision(10) << std::fixed << value(stars, low) << std::endl;

    return 0;
}



