#include <iostream>
#include "include/number_theory_basics.hpp"

using namespace std;
using namespace NumberTheory;

int main()
{
    ll n;
    cin >> n;
    ll temp = n;
    ull sum = 0;
    while(temp != 0) {
        sum += factorial(temp % 10);
        temp /= 10;
    }
    if(sum == (ull)n) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
