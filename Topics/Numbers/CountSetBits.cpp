int countSetBitsFrom1ToN(int n)
{
  int count = 0;
  for (int i = 1; i <= n; i++)
    count += __builtin_popcount(i);
  return count;
}

int main()
{
  int n = 10;
  cout << "Total set bits from 1 to " << n << ": " << countSetBitsFrom1ToN(n) << endl;
  return 0;
}
