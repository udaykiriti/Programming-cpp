#include <bits/stdc++.h>
using namespace std;

int sqrtBinarySearch(int x)
{
  if (x == 0 || x == 1)
    return x;
  int low = 1, high = x, ans;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (mid <= x / mid)
    {
      low = mid + 1;
      ans = mid;
    }
    else
    {
      high = mid - 1;
    }
  }
  return ans;
}

int main()
{
  int x = 49;
  cout << "Square root of " << x << ": " << sqrtBinarySearch(x) << endl;
  return 0;
}
