#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    	vector<int> results;
    	for (int i = 0; i < findNums.size(); ++i) {
    		bool get_greater_num = false;
	    	auto pos = find(nums.begin(), nums.end(), findNums[i]);
	    	for (auto p = pos; p != nums.end(); ++p) {
	    		if (*p> findNums[i]) {
	    			results.push_back(*p);
	    			get_greater_num = true;
	    			break;
	    		}
	    	}
	    	if (!get_greater_num) {
	    		results.push_back(-1);
	    	}
    	}

    	return results;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<int> findNums = {2,4};
	vector<int> nums = {1,2,3,4};
	vector<int> r = s.nextGreaterElement(findNums, nums);
	for (int i = 0; i < r.size(); ++i) {
		cout << r[i] << endl;
	}
	return 0;
}
