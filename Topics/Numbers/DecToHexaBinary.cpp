#include <string>
using namespace std;

string toBinary(int n)
{
  string res;
  while (n)
  {
    res = char((n % 2) + '0') + res;
    n /= 2;
  }
  return res.empty() ? "0" : res;
}

string toHex(int n)
{
  string hex = "0123456789ABCDEF", res;
  while (n)
  {
    res = hex[n % 16] + res;
    n /= 16;
  }
  return res.empty() ? "0" : res;
}

int main()
{
  int n = 255;
  cout << "Binary: " << toBinary(n) << ", Hex: " << toHex(n) << endl;
  return 0;
}
