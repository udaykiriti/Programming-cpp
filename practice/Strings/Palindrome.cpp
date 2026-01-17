#include <iostream>
using namespace std;

int main()
{
  string str;
  getline(cin, str);
  int len = 0;
  while (str[len] != '\0')
    len++;
  bool isPalin = true;
  for (int i = 0; i < len / 2; i++)
  {
    if (str[i] != str[len - 1 - i])
    {
      isPalin = false;
      break;
    }
  }
  cout << (isPalin ? "Yes" : "No") << endl;
  return 0;
}
