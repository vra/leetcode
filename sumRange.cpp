#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
class NumArray {
public:
    NumArray(vector<int> &nums):p_sum(nums.size()+1, 0) {
		partial_sum(nums.begin(), nums.end(), p_sum.begin()+1);
    }

    int sumRange(int i, int j) {
		return p_sum[j+1] - p_sum[i];
    }
private:
	vector<int> p_sum;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

int main()
{
	vector<int> nums;
	nums.push_back(-2);
	nums.push_back(0);
	nums.push_back(3);
	nums.push_back(-5);
	nums.push_back(2);
	nums.push_back(1);

	NumArray numArray(nums);
	int a= numArray.sumRange(0,1);
	int b= numArray.sumRange(1,2);
	int c= numArray.sumRange(2,3);
	int d= numArray.sumRange(1,5);
	

	return 0;
}