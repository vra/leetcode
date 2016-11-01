#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Solution{
	public:
	int thirdMax(vector<int>& nums){
		if (nums.size() < 3) return *(max_element(nums.begin(),nums.end()));
		long m1 = LONG_MIN;
		long m2 = LONG_MIN;
		long m3 = LONG_MIN;

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > m1){
				m3 = max(m3, m2);
				m2 = max(m2, m1);
				m1 = nums[i];
			}	
			else if (nums[i] > m2){
				if (nums[i] == m1) continue; // m1,m2,m3 can't be equal
				m3 = max(m3, m2);
				m2 = nums[i];
			}
			else if (nums[i] > m3){
				if (nums[i] == m2) continue;// m1,m2,m3 can't be equal
				m3 = nums[i];
			}
		}
		cout << m1 << m2 << m3 << endl;
		if (m3 == LONG_MIN) return m1;
		return m3;	
	}
};

int main(){
	Solution s = Solution();
	vector<int> v ={2,1,INT_MIN};
	int i = s.thirdMax(v);
	cout << i << endl;
	return 0;
}
