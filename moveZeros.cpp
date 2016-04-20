#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	//Move from tail of vector, stop when meet zero
    void moveZeroes(vector<int>& nums) {
		for (int i = nums.size() - 1; i >= 0; --i) 
		{
			if (nums[i] == 0)
			{
				for (int j = i+1; j < nums.size(); ++j)
				{
					if (nums[j] == 0)
					{
						break;
					}

					//exchange nums[j-1] and nums[j]
					int tmp = nums[j];
					nums[j] = nums[j-1];
					nums[j-1] = tmp;
				}
			}
		}
    }
	void moveZeroesInsertIndex(vector<int>& nums)
	{
		int index = 0;

		//Move all non-zero elements as forward as possible
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] != 0)
			{
				nums[index++] = nums[i];
			}
		}

		//Fill remaining fields with zeros
		while (index < nums.size())
		{
			nums[index++] = 0;

		}
	}
};


int main()
{
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(3);
	nums.push_back(12);

	Solution s = Solution();
	s.moveZeroes(nums);

	return 0;
}