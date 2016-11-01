#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// Solution1: 2 layer of loop
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> result = vector<int>(nums.size(), 1);
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = 0; j < nums.size(); ++j) {
				if (j != i) result[j] *= nums[i];
			}
		}	

		return result;
	}

	// Solution2: calculate the product of all nums first,
	// then division each num to get the final result.
	vector<int> productExceptSelf2(vector<int>& nums) {
		vector<int> result = vector<int>(nums.size(), 1);
		int all_product = 1;
		for (int i = 0; i < nums.size(); ++i) {
			all_product *= nums[i];
		}
		for (int i = 0; i < nums.size(); ++i) {
			result[i] = all_product / nums[i];	
		}
		return result;
	}
	// Solution3: calculate the left product first,
	// then calulate the right product.
	vector<int> productExceptSelf3(vector<int>& nums) {
		vector<int> result = vector<int>(nums.size(), 1);
		// First loop, get the product of all nums at its left
		for (int i = 1; i < nums.size(); ++i) {
			result[i] = result[i-1] * nums[i-1];
		}
		int right = 1;
		// Second loop, product the product of nums in its right
		for (int i = nums.size()-1; i >=0; --i) {
			result[i] *= right;
			right *= nums[i];
		}

		return result;
	}
};


int main() {
	Solution s = Solution();
	vector<int> v = {2,4,5,4};
	vector<int> r = s.productExceptSelf3(v);
	cout << r[0] << r[1] << endl;
}
