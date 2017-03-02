#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	for (int i = 0; i < nums.size(); ++i) {
    		if (nums[i] >= target) return i;
    	}
    	return nums.size();
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<int> v = {1,3,5,6};
	cout << s.searchInsert(v,5) << endl;
	cout << s.searchInsert(v,2) << endl;
	cout << s.searchInsert(v,7) << endl;
	cout << s.searchInsert(v,0) << endl;
	return 0;
}
