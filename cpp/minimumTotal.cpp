#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
	int minimumTotal(vector<vector<int> > &triangle) 
	{
		int size = triangle.size();
		vector<int> minLen = triangle.back();

		for (int i = size - 2; i >= 0; i--)
		{
			for (int j = 0; j <= i; j++)
			{
				minLen[j] = min( minLen[j], minLen[j + 1]) + triangle[i][j];
			}			
		}

		return minLen[0];
    }

};

int main()
{
	vector<vector<int>> t;
	vector<int> t1;
	t1.push_back(2);
	vector<int> t2;
	t2.push_back(3);
	t2.push_back(4);
	vector<int> t3;
	t3.push_back(6);
	t3.push_back(5);
	t3.push_back(7);
	vector<int> t4;
	t4.push_back(4);
	t4.push_back(1);
	t4.push_back(8);
	t4.push_back(3);

	t.push_back(t1);
	t.push_back(t2);
	t.push_back(t3);
	t.push_back(t4);

	Solution s;
	int a = s.minimumTotal(t);

	return 0;
}
