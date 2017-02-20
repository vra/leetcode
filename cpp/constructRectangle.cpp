#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
		vector<int> result;
		int W = int(sqrt(area));
		if (W*W == area) {
			result.push_back(W);
			result.push_back(W);
			return  result;
		}

		while (area % W != 0)
		{
			--W;
		}

		result.push_back(area/W);
		result.push_back(W);
		return result;
    }
};

int main() {
	Solution s;
	vector<int> r = s.constructRectangle(101);
	for (int i = 0; i < r.size(); ++i) {
		cout << r[i] << endl;
	}

	return 0;
}
