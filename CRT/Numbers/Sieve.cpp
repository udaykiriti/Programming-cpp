#include <vector>
#include <algorithm>
using namespace std;
int countPrimes(int n)
{
  if (n <= 2)
    return 0;
  vector<bool> isPrime(n, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i * i < n; ++i)
    if (isPrime[i])
      for (int j = i * i; j < n; j += i)
        isPrime[j] = false;
  return count(isPrime.begin(), isPrime.end(), true);
}

int main()
{
  int n = 20;
  cout << "Primes less than " << n << ": " << countPrimes(n) << endl;
  return 0;
}
