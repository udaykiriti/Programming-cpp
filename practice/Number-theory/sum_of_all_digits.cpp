#include <iostream>
#include "include/number_theory_basics.hpp"

using namespace std;
using namespace NumberTheory;

int main()
{
  ll n;
  cout << "Enter a number: ";
  cin >> n;
  cout << "Digital Root: " << digital_root(n) << endl;
  return 0;
}
