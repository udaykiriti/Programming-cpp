#include <iostream>
#include "include/number_theory_basics.hpp"
#include "include/diophantine.hpp"

using namespace std;
using namespace NumberTheory;

/*
 * Linear Diophantine Equation Solver
 *
 * Solves equations of the form ax + by = c for integer solutions x, y.
 *
 * Theory:
 *   - The equation has integer solutions if and only if gcd(a, b) divides c.
 *   - One solution (x0, y0) is found using the Extended Euclidean Algorithm.
 *   - General solution: x = x0 + k*(b/g), y = y0 - k*(a/g)
 *
 * Resources:
 *   - CP-Algorithms: https://cp-algorithms.com/algebra/linear-diophantine-equation.html
 *   - GeeksforGeeks: https://www.geeksforgeeks.org/linear-diophantine-equations/
 */
int main() {
    ll a, b, c;
    cout << "Solve: ax + by = c" << endl;
    cout << "Enter a, b, c: ";
    cin >> a >> b >> c;
    ll x, y;
    bool found = solveLDE(a, b, c, x, y); // Updated call to match fix
    if (found) {
         cout << "Solution: x = " << x << ", y = " << y << endl;
    } else {
         cout << "No solution exists" << endl;
    }
    return 0;
}
