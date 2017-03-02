#include <iostream>	
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	vector<int> dp(nums.size(),0);
    	int my_max = 0;
    	dp[0] = nums[0];

    	for (int i = 1; i < nums.size(); ++i) {
    		//maxSubArray(A, i) = maxSubArray(A, i - 1) > 0 ? maxSubArray(A, i - 1) : 0 + A[i]; 
    		//dp[i] means the maximum subarray ending with A[i];
    		dp[i] = nums[i] + (dp[i-1] > 0 ? dp[i-1] : 0);
    		my_max  = max(my_max, dp[i]);
    	}

    	return my_max;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
	cout << s.maxSubArray(nums) << endl;
	return 0;
}
