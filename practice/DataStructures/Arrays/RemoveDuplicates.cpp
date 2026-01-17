#include <bits/stdc++.h>
using namespace std;

int main()
{
  int arr[] = {4, 5, 4, 3, 2, 4, 2};
  int n = sizeof(arr) / sizeof(arr[0]);
  int i, j, k;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n;)
    {
      if (arr[i] == arr[j])
      {
        for (k = j; k < n - 1; k++)
        {
          arr[k] = arr[k + 1];
        }
        n--;
      }
      else
      {
        j++;
      }
    }
  }
  printf("\n The array element after removing duplicates\n");
  for(int i=0;i<n;i++) cout<<arr[i]<<endl;
  return 0;
}
