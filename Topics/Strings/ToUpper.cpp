#include <iostream>
using namespace std;

int main()
{
  string str;
  getline(cin, str);
  for (int i = 0; str[i] != '\0'; i++)
  {
    char ch = str[i];
    if (ch >= 'a' && ch <= 'z')
      ch = ch - 32;
    cout << ch;
  }
  cout << endl;
  return 0;
}
