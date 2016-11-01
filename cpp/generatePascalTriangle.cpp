#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generate(int numRows) 
{
	vector<vector<int> > res;

	if (numRows < 1)
	{
		return res;
	}

	vector<int> before;
	before.push_back(1);

	res.push_back(before);

	vector<int> curr;

	for (int i = 1; i < numRows; i++)
	{
		curr.push_back(1);

		for (int j = 0; j < before.size() - 1; j++)
		{
			curr.push_back(before[j] + before[j + 1]);
		}

		curr.push_back(1);

		res.push_back(curr);
		before = curr;
		curr.clear();
	}
        
	return res;
}

int main()
{
	vector<vector<int> > a = generate(5);

	return 0;
}
