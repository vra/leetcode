#include <iostream>

class Solution {
public:
    int countPrimes0(int n) {
		if (n < 2) return 0;
		int numOfPrimers = n - 1;
		for (int i = 3; i <= n;  ++i)
		{
			if (i % 2 == 0) 
			{
				numOfPrimers --;
				continue;
			}
			for (int j = 3; j <= int(sqrt(i)); ++j)
			{
				if (i % j == 0)
				{
					numOfPrimers --;
					break;
				}
			}
		}

		return numOfPrimers;
    }

	int countPrimes(int n)
	{
		bool *isPrime = new bool[n]; 
		for (int i = 2; i < n; i++) 
		{
			isPrime[i] = true;
		}
		// Loop's ending condition is i * i < n instead of i < sqrt(n)
		// to avoid repeatedly calling an expensive function sqrt().
		for (int i = 2; i * i < n; i++) 
		{
			if (!isPrime[i]) continue;
			for (int j = i * i; j < n; j += i) 
			{
				isPrime[j] = false;
			}
		}

		int count = 0;
		for (int i = 2; i < n; i++) 
		{
			if (isPrime[i]) count++;
		}
		return count;
	} 
};


int main()
{
	Solution s= Solution();
	
	int a = s.countPrimes(5);

	return 0;
	
}