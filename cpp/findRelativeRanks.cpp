#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
		vector<int> idx(nums.size());
		iota(idx.begin(), idx.end(), 0);
		sort(idx.begin(), idx.end(), [&nums](int i1,int i2){return nums[i1] > nums[i2];});

		vector<string> result;
		vector<string> title(nums.size());
		if (nums.size() > 0) title[idx[0]] = "Gold Medal";
		if (nums.size() > 1) title[idx[1]] = "Silver Medal";
		if (nums.size() > 2) title[idx[2]] = "Bronze Medal";
		for (int i = 3; i < idx.size(); ++i) {
			title[idx[i]] = to_string(i+1);
		}

		for (int i = 0; i < idx.size(); ++i) {
			result.push_back(title[i]);
		}

		return result;
    }
};


int main() {
	Solution s;
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
/*	a.push_back(3);
	a.push_back(4);
	a.push_back(1);
	*/
	vector<string> r = s.findRelativeRanks(a);
	for (int i = 0; i < r.size(); ++i) {
		cout<< r[i] << endl;
	}

	return 0;
}
