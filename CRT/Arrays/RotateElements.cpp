#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main()
{
  int arr[] = {5, 4, 3, 2, 1};

  int i, temp;
  int n = sizeof(arr) / sizeof(arr[0]);
  temp = arr[0];
  for (int i = 0; i < n; i++)
    arr[i] = arr[i + 1];

  arr[n - 1] = temp;

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}