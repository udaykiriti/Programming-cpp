#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, rev = 0, org, rem;
  cin >> n;
  org = n;
  while (n != 0)
  {
    rem = n % 10;
    rev = rev * 10 + rem;
    n /= 10;
  }
  if (org == rev)
    cout << "palindrome";
  else
    cout << "Not a palindrome";
}