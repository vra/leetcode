#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Solution {

public:

    int findPairs(vector<int>& nums, int k) {
		if (nums.size() < 1) return 0;
		set<set<int>> k_diff_pairs;
		for (size_t i = 0; i < nums.size()-1; ++i) {
			for (size_t j = i+1; j < nums.size(); ++j) {
				if (abs(nums[i]-nums[j]) == k) {
					set<int> tmp_set =  {nums[i], nums[j]};
					k_diff_pairs.insert(tmp_set);
				}
			}
		}
		
		return k_diff_pairs.size();
    }
};

int main() {
	Solution s;
	//vector<int> nums = {3,1,4,1,5};
	vector<int> nums = {};
	//vector<int> nums = {1,2,3,4,5};
	//vector<int> nums = {1,3,1,5,4};
	int ret = s.findPairs(nums, 2);
	cout << ret << endl;
	return 0;
}
