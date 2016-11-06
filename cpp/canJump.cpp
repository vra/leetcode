#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
		int i = 0;
		int n = nums.size();
		for (int reach = 0; i < n && i <= reach; ++i) {
			cout << i + nums[i] << ' ' << reach << endl;
			reach = max(i + nums[i], reach);
		}
		return i == n;
    }
};


int main() {
	Solution s = Solution();
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(5);
	nums.push_back(9);
	nums.push_back(3);
	nums.push_back(7);
	nums.push_back(3);
	nums.push_back(18);
	bool r = s.canJump(nums);

	return 0;
}
