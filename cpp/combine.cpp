#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > result;
		if (k > n) return result;
		if (k == 1) {
			for (int i = 0; i < n; ++i) {
				result.push_back(vector<int>(1,i+1));
			}
			return result;
		}
		for (int i = n; i > 1; --i) {
			vector<vector<int>> tmp_result = combine(i-1, k-1);
			for (int j = 0; j < tmp_result.size(); ++j) {
				tmp_result[j].push_back(i);
				result.push_back(tmp_result[j]);
			}

		}
		return result;
	}
};

int main() {
	Solution s = Solution();
	vector<vector<int> > r = s.combine(10,10);

	return 0;
}
