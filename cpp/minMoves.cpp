#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
    //TOO SLOW!
    //actually, ans = sum - minNum * n
		int count = 0;
		while (adjacent_find(nums.begin(), nums.end(), std::not_equal_to<int>()) != nums.end())
		{
			sort(nums.begin(), nums.end());
			for (int i = 0; i < nums.size()-1; ++i){
				nums[i] += nums[i];
			}
			++ count;
		}

		return count;
    }
};

int main() {
	Solution s;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	cout << s.minMoves(v) << endl;

	return 0;
}
