#define ULL unsigned long long int

const int SPRP[3] = {2, 7, 61};

ULL pow(ULL a, ULL x, ULL n)
{
	ULL res = 1;
	while(x)
	{
		if(x & 1)
		{
			res = res * a % n;
			a = a * a % n;
		}
		x >>= 1;
	}
	return res;
}

bool miller_rabin(int a, int n)
{
	int u = n - 1;
	while(!(u & 1)) u >>= 1;

	int x = pow(a, u, n);
	if(x == 1) return true;

	while(u <= n - 1)
	{
		if(x == n - 1) return true;
		x = x * x % n;
		u <<= 1;
	}

	return false;
}

bool isprime(int n)
{
	if(n < 2) return false;
	for(unsigned int i = 0; i < 3; ++i)
	{
		if(!miller_rabin(SPRP[i], n)) return false;
	}
	return true;
}