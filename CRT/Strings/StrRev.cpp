#include <iostream>
using namespace std;

int main()
{
  string str;
  getline(cin, str);
  int len = 0;
  while (str[len] != '\0')
    len++;
  for (int i = len - 1; i >= 0; i--)
    cout << str[i];
  cout << endl;
  return 0;
}
