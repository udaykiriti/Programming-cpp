#include <iostream>
using namespace std;

int main()
{
  string str1, str2;
  getline(cin, str1);
  getline(cin, str2);
  int len1 = 0, len2 = 0;
  while (str1[len1] != '\0')
    len1++;
  while (str2[len2] != '\0')
    len2++;

  if (len1 != len2)
  {
    cout << "No" << endl;
    return 0;
  }

  int count1[256] = {0}, count2[256] = {0};
  for (int i = 0; i < len1; i++)
  {
    count1[(int)str1[i]]++;
    count2[(int)str2[i]]++;
  }

  for (int i = 0; i < 256; i++)
  {
    if (count1[i] != count2[i])
    {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}
