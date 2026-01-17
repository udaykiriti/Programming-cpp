#include <iostream>
#include "include/number_theory_basics.hpp"

using namespace std;
using namespace NumberTheory;

int main()
{
  ll num;
  cin >> num;
  if(is_perfect(num)) cout<<"YES";
  else cout<<"NO";
  return 0;
}
