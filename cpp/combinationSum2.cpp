#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<int> local;
		vector<vector<int>> res;
		sort(candidates.begin(), candidates.end());
		findCombination(res, candidates, 0, local, target);
		return res;
    }

	void findCombination(vector<vector<int>> &res, vector<int>& nums, int order, vector<int> &local, int target) {
		if (target == 0) {
			res.push_back(local);
			return;
		}
		for (int i = order; i < nums.size(); ++i) {
			if (nums[i] > target) return;
			if (i && nums[i]==nums[i-1] && i > order) continue;
			local.push_back(nums[i]);
			findCombination(res, nums, i+1, local, target - nums[i]);
			local.pop_back();
		}
	}
};


int main() {
	Solution s;
	vector<int> nums;
	nums.push_back(10);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(6);
	nums.push_back(1);
	nums.push_back(5);
	vector<vector<int>> r = s.combinationSum2(nums, 8);

	return 0;
}
