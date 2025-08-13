#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int n)
{
  string s = to_string(n);
  return s == string(s.rbegin(), s.rend());
}

int nextPalindrome(int n)
{
  n++;
  while (!isPalindrome(n))
    n++;
  return n;
}

int main()
{
  int n = 123;
  cout << "Next palindrome: " << nextPalindrome(n) << endl;
  return 0;
}
