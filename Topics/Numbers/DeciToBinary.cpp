#include <iostream>
using namespace std;

int main()
{
  int num;
  cout << "Enter a decimal number: ";
  cin >> num;

  string binary = "";
  int temp = num;

  while (temp > 0)
  {
    binary = to_string(temp % 2) + binary;
    // binary+=to_string(temp%2);
    temp /= 2;
  }

  cout << "Binary of " << num << " is: " << binary << endl;
  return 0;
}
