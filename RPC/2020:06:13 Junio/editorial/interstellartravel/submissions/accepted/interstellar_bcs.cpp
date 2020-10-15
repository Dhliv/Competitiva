#include <iostream>
#include <vector>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>

#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<double, ll> di;
typedef vector<di> vdi;
typedef vector<double> vd;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

int main() {
    ll N;
    cin >> N;
    vd T(N), s(N);
    vd a(N);
    for (ll i = 0; i < N; ++i) {
        cin >> T[i] >> s[i] >> a[i];
    }

    vdd dist_deriv;
    double cur = 0;
    for (ll i = 0; i < N; ++i) {
        if (s[i] != 0 && T[i]/s[i] < M_PI) {
            dist_deriv.emplace_back(a[i] - T[i]/s[i], s[i]);
            dist_deriv.emplace_back(a[i], -s[i]*2);
            dist_deriv.emplace_back(a[i] + T[i]/s[i], s[i]);
        
            dist_deriv.emplace_back(a[i] - T[i]/s[i] + 2*M_PI, s[i]);
            dist_deriv.emplace_back(a[i] + 2*M_PI, -s[i]*2);
            dist_deriv.emplace_back(a[i] + T[i]/s[i] + 2*M_PI, s[i]);
        } else {
            cur += T[i] - s[i]*M_PI;
            dist_deriv.emplace_back(a[i] - M_PI, s[i]);
            dist_deriv.emplace_back(a[i], -s[i]*2);
            dist_deriv.emplace_back(a[i] + M_PI, 2*s[i]);
            dist_deriv.emplace_back(a[i] + 2*M_PI, -s[i]*2);
            dist_deriv.emplace_back(a[i] + 3*M_PI, s[i]);
        }
    }

    sort(dist_deriv.begin(), dist_deriv.end());

    double last_angle = dist_deriv[0].f;
    double best = cur;
    double c_deriv = 0;

    for (ll i = 0; i < dist_deriv.size(); ++i) {
        cur += c_deriv * (dist_deriv[i].f - last_angle);
        c_deriv += dist_deriv[i].s;
        last_angle = dist_deriv[i].f;
        best = max(best, cur);
    }

    printf("%.6lf\n", best);
}
