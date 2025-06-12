#include <bits/stdc++.h>
using namespace std;

const int m = 1e9 + 7;

int findPower(long long a, long long b)
{
  if (b == 0)
    return 1;
  long long half = findPower(a, b / 2);
  long long result = (half * half) % m;
  if (b % 2 == 1)
  {
    result = (result * a) % m;
  }
  return result;
}

int countGoodNumbers(long long n)
{
  long long even_pos = (n + 1) / 2;
  long long odd_pos = n / 2;

  long long pow1 = findPower(5, even_pos);
  long long pow2 = findPower(4, odd_pos);

  return (pow1 * pow2) % m;
}

int main()
{
  long long n;
  cin >> n;
  cout << countGoodNumbers(n) << endl;
  return 0;
}
