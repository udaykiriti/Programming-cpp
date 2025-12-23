#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n; cin >> n;
  float x, sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    sum += x;
  }
  float avg = sum / n;
  cout << avg;
}