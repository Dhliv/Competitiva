#include "jngen.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv);
    parseArgs(argc, argv);

    int n = getOpt(0);
    // int m = getOpt(1);

    // cout << Graph::random(n, m).connected().g().shuffled().printN().printM().add1() << endl;
    cout << Tree::star(n).shuffledAllBut({0}).printN().printM().add1() << endl;

    return 0;
}
