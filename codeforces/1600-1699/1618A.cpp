#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int t(1); cin >> t;
  while (t--) { 
    int b[7];
    for (int i = 0; i < 7; i++) cin >> b[i];
    int a1 = b[0];
    int x = b[6] - b[0];
    int a2 = b[1];
    int a3;
    for (int i = 2; i < 7; i++) {
      if (x - a2 == b[i]) {
        a3 = b[i];
        break;
      }
    }
    cout << a1 << " " << a2 << " " << a3 << endl;
  } return 0;
}
