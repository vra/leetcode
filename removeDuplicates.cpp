#include <iostream>

using namespace std;


int removeDuplicates(int A[], int n) 
{
	if (n == 0)
	{
		return n; 
	}
	
	int k = 0;
	for (int i = 1; i < n; i++)
	{
		if (A[i] != A[k])
		{
			A[++k] = A[i];
		}
		
	} 
	return k+1;
}

int main()
{
	int A[] ={1,1,2};
	
	removeDuplicates(A,3);
	cout << A[0] << A[1] << endl;
}
