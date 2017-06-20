#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countArrangement(int N) {
		vector<int> vs;
		for (int i = 0; i < N; ++i) {
			vs.push_back(i+1);
		}
		return count(N, vs);
    }

	int count(int n, vector<int> &vs) {
		if (n <= 0) return 1;
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (vs[i] % n == 0 || n % vs[i] == 0) {
				swap(vs[i], vs[n-1]);
				ans += count(n-1, vs);
				swap(vs[i], vs[n-1]);
			}
		}
		return ans;
	}
};


int main() {
	Solution s;
	cout << s.countArrangement(2) << endl;
	cout << s.countArrangement(3) << endl;

	return 0;
}
