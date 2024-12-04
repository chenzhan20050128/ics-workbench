#include <stdio.h>

#define N 10000000

int *sieve(int n);

int main()
{
  int *primes = sieve(N - 1);
  int count = 0;
  for (int *cur = primes; *cur; cur++)
  {
    count++;
  }
  // printf("素数总数：%d\n", count);
  return 0;
}