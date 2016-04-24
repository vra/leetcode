#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		set<int> numSet;
		for (int num: nums)
		{
			if (numSet.find(num) != numSet.end())
			{
				return true;
			}
			numSet.insert(num);
		}

		return false;
    }
};

int main()
{
	Solution s = Solution();

	vector<int> nums;
	nums.push_back(9);
	nums.push_back(5);
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(9);
	
	bool b = s.containsDuplicate(nums);

	return 0;
}