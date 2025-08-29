#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  string s; cin >> s;
  int count = 0;
  int n = s.length();
  for (int i = 0; i < n; ++i)
    if (s[i] == 'Q')
      for (int j = i + 1; j < n; ++j)
        if (s[j] == 'A')
          for (int k = j + 1; k < n; ++k)
            if (s[k] == 'Q')
              count++;

  cout << count << endl;
  return 0;
}