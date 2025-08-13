#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)

int main()
{
  int n;
  cin >> n;
  int arr[n];

  FOR(i, 0, n)
  {
    scanf("%d", &arr[i]);
  }

  int first = INT_MIN, second = INT_MIN;

  FOR(i, 0, n)
  {
    if (arr[i] > first)
    {
      second = first;
      first = arr[i];
    }
    else if (arr[i] > second && arr[i] != first)
    {
      second = arr[i];
    }
  }

  if (second == INT_MIN)
    printf("No second largest element exists.\n");
  else
    printf("Second largest element is %d\n", second);

  return 0;
}
