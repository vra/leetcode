#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex)
{
	vector<int> res (rowIndex + 1, 0);

	res[0] = 1;

	for (int i = 0; i < rowIndex + 1; i++)
	{
		for (int j  = i; j >= 1; j--)
		{
			res[j] += res[j - 1];
		}
	}

	return res;
}

int main()
{
	vector<int> a = getRow(3);

	return 0;

}
