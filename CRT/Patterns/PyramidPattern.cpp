#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void printStars(int blanks, int stars)
{
  for (int i = 1; i <= blanks; i++)
    cout << " ";
  for (int i = 1; i <= stars; i++)
    cout << "* ";
  cout << endl;
}

int main()
{
  int lines = 15;
  int blanks = 30;
  for (int i = 1; i <= lines; i++)
  {
    printStars(blanks, i);
    blanks--;
  }
}
