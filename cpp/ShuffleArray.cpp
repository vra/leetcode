#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(vector<int> nums) {
		my_nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
		return my_nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
		vector<int> order;
		for (int i = 0; i < my_nums.size(); ++i){
			order.push_back(i);
		}
		random_shuffle(order.begin(), order.end());

		vector<int> result;
		for (int i = 0; i < order.size(); ++i){
			result.push_back(my_nums[order[i]]);
		}

		return result;
    }
private:
	vector<int> my_nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	Solution s = Solution(v);
	
	vector<int> r1 = s.reset();
	vector<int> r2 = s.shuffle();

	return 0;
}
