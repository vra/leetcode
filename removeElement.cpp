#include <iostream>

using namespace std;

int removeElement(int A[], int n, int elem) 
{
	int begin = 0;
	for (int i = 0; i <n; i++)
	{
		if (A[i] != elem)
		{
			A[begin++]=A[i];
		}
	}

	return begin;
}


int removeElement2(int A[], int n, int elem)
{
	int i = 0;
	while (i < n)
	{
		if (A[i] == elem)
		{
			A[i] = A[n - 1];
			n--; 
		}
		else
		{
			i++;
		}
	}

	return n;
}

int main()
{
	int A[]={1,2,3,3,4,5,3};
	int l = removeElement2(A, 7, 3);

	for (int i = 0; i < l; i++)
	{
		cout << A[i] << endl;
	}

	return 0;
	
}
