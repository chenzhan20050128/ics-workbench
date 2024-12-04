#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 10000000

static unsigned char is_prime[(N + 7) / 8];
static int primes[N];

#define IS_PRIME(n) (is_prime[(n) / 8] & (1 << ((n) % 8)))
#define SET_COMPOSITE(n) (is_prime[(n) / 8] &= ~(1 << ((n) % 8)))

int *sieve(int n)
{
  memset(is_prime, 0xFF, sizeof(is_prime));
  SET_COMPOSITE(0);
  SET_COMPOSITE(1);
  int sqrt_n = (int)sqrt(n);

  for (int i = 2; i <= sqrt_n; i++)
  {
    if (IS_PRIME(i))
    {
      for (int j = i * i; j <= n; j += i)
      {
        SET_COMPOSITE(j);
      }
    }
  }

  int *p = primes;
  for (int i = 2; i <= n; i++)
  {
    if (IS_PRIME(i))
    {
      *p++ = i;
    }
  }
  *p = 0;
  return primes;
}