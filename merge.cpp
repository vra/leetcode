#include <iostream>

using namespace std;


void merge(int A[], int m, int B[], int n) 
{
	int i = n;
	int j = m;

	int c = 0;
	while (i > 0 && j > 0 )
	{
		if (B[i - 1] >= A[j - 1])
		{
			A[m + n - 1 - c] = B[i - 1];
			c++;
			i--;
		}
		else
		{
			A[m + n - 1 - c] = A[j - 1];
			c++;
			j--;
		}
	}
	
	if (i > 0)
	{
		for (int k = i; k > 0; k--)
		{
			A[m + n - 1 - c] = B[k - 1];
			c++;
		}
	}
	else if (j > 0)
	{
		for (int k = j; k > 0; k--)
		{
			A[m + n - 1 - c] = A[k - 1];
			c++;
		}
	}
        
}
int main()
{
	int A[10] ={1};
	int B[] ={5};

	merge(A, 1, B, 1);

	return 0;
}
