#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum1(vector<int>& numbers, int target) {
		vector<int> result;
		for (int i = 0; i < numbers.size()-1; ++i) {
			for (int j = i + 1; j < numbers.size(); ++j) {
				int curr_sum = numbers[i] + numbers[j];
				if (curr_sum > target) {
					break;
				}
				if (curr_sum == target) {
					result.push_back(i+1);
					result.push_back(j+1);
					return result;
				}
			}
		}
		return result;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> result;
		for (int i =0, j = numbers.size() - 1; ;) {
			if (numbers[i] +numbers[j] > target) --j;
			else if (numbers[i] + numbers[j] < target) ++i;
			else {
				result.push_back(i+1);
				result.push_back(j+1);
				return result;
			}
		}
	}
};

int main() {
	Solution s = Solution();
	vector<int> n;
	n.push_back(2);
	n.push_back(7);
	n.push_back(11);
	n.push_back(17);
	vector<int> r = s.twoSum(n, 28);
	
	return 0;
}
