// Solve problem: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/?tab=Description
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    	vector<int>  num_appear(nums.size()+1);
    	for (int i = 0; i < nums.size(); ++i) {
    		++num_appear[nums[i]];
    	}

    	vector<int> disappered_numbers;
    	for (int i = 1; i < num_appear.size(); ++i) {
    		if (! num_appear[i]) {
    			disappered_numbers.push_back(i);
    		}
    	}

    	return disappered_numbers;
    }
};

int main() {
	cout << "hello" << endl;
	Solution s;
	vector<int> nums = {3,3,3};
	vector<int> result = s.findDisappearedNumbers(nums);
	for (int i = 0; i < result.size();++i) {
		cout << result[i] << endl;
	}

	return 0;
}
