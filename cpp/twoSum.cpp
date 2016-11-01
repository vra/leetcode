#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	//Assume that there only have exactly one solution
    vector<int> twoSum(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = i+1; j< nums.size(); ++j)
			{
				if (nums[i] + nums[j] == target)
				{
					vector<int> result;
					result.push_back(i);
					result.push_back(j);

					return result;
				}
			}
		}
    }

    vector<int> twoSumHot(vector<int>& nums, int target) {
		vector<int> result;
		unordered_map<int, int> hash;


		for (int i = 0; i < nums.size(); ++i)
		{
			int numToBeFound = target - nums[i];
			if (hash.find(numToBeFound) != hash.end())
			{
				//We put number to hash first, so get the index of last number first!
				result.push_back(hash[numToBeFound]);
				result.push_back(i);
				return result;
			}

			hash[nums[i]] = i;
		}
		return result;
	}
};

int main()
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);
	
	Solution s = Solution();
	vector<int> result = s.twoSumHot(nums, 9);

	return 0;
}