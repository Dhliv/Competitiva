#define ld long double

ld ternary_search(ld l, ld r) {
    ld eps = 1e-9;
    ld m1, m2, f1, f2;
    while (r - l > eps) {
        m1 = l + (r - l) / 3;
        m2 = r - (r - l) / 3;
        f1 = f(m1);      //evaluates the function at m1
        f2 = f(m2);      //evaluates the function at m2
        if (f1 < f2) l = m1;
        else r = m2;
    }

    //return the maximum of f(x) in [l, r]
    return f(l);
}