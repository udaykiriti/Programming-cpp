#include <iostream>
using namespace std;

int main()
{
  int a, b, gcd, lcm;

  cout << "Enter two numbers: ";
  cin >> a >> b;

  int x = a, y = b;
  while (y != 0)
  {
    int temp = y;
    y = x % y;
    x = temp;
  }
  gcd = x;
  lcm = (a * b) / gcd;

  cout << "GCD: " << gcd << endl;
  cout << "LCM: " << lcm << endl;

  return 0;
}
