#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       map<int, int> NumPosition;
	   for (int i = 0; i < nums.size(); ++i)
	   {
		   //It's important to remove the number out of range and rewrite with current position.
		   if (i > k)
		   {
			   NumPosition.erase(NumPosition[i -k -1]);
		   }

		   if (NumPosition.find(nums[i]) == NumPosition.end())
		   {
			   NumPosition.insert(make_pair(nums[i], i));
		   }
		   else
		   {
			   if (abs(i - NumPosition[nums[i]]) <= k)
			   {
				   return true;
			   }
		   }
	   }

	   return false;
    }
};

int main()
{
	Solution s = Solution();
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(1);

	bool r = s.containsNearbyDuplicate(nums, 1);
	
	return 0;
}