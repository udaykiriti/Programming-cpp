#include <iostream>
using namespace std;

int main()
{
  string str;
  getline(cin, str);
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (str[i] == ' ')
      cout << '-';
    else
      cout << str[i];
  }
  cout << endl;
  return 0;
}
