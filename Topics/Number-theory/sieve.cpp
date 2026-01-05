#include <iostream>
#include "include/number_theory_basics.hpp"

using namespace std;
using namespace NumberTheory;

int main()
{
  ll n;
  cout << "Enter limit: ";
  cin >> n;
  cout << "Primes less than " << n << ": " << count_primes_sieve(n) << endl;
  return 0;
}
