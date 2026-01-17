#include <iostream>
#include "include/number_theory_basics.hpp"

using namespace std;
using namespace NumberTheory;

int main() {
    ll n, r, m;
    cout << "Calculate nCr % m\nEnter n, r, m: ";
    cin >> n >> r >> m;
    
    cout << "Result: " << nCr(n, r, m) << endl;
    return 0;
}
