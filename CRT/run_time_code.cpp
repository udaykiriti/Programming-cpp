#include <bits/stdc++.h>
using namespace std;

int main()
{
  auto start = chrono::high_resolution_clock::now();
  // heres the code
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double, milli> duration = end - start;
  cout << "Run time: " << duration.count() << " ms" << endl;

  return 0;
}