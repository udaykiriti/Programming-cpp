#include <bits/stdc++.h>
using namespace std;
//inputs -n(number)
//variables-reversenumber,n
//output-reversed number
int reverseNumber(int n){
  int rev=0;
  while (n>0)
  {
    rev=rev*10+n%10;
    n=n/10;
  }
  return rev;
}

int main()
{
  int n;
  cin >> n;
  cout<<reverseNumber(n);
}

