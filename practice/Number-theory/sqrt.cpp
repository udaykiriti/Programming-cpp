#include <iostream>
#include "include/number_theory_basics.hpp"

using namespace std;
using namespace NumberTheory;

int main()
{
  ll x;
  cout << "Enter a number: ";
  cin >> x;
  cout << "Square root of " << x << ": " << sqrt_binary_search(x) << endl;
  return 0;
}
