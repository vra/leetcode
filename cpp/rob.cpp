#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {

		int oddSum = 0;
		int evenSum  = 0;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (i % 2 == 0)
			{
				oddSum = max(oddSum + nums[i], evenSum);
			}
			else
			{
				evenSum = max(evenSum+ nums[i], oddSum);
			}
		}

		return max(oddSum, evenSum);
    }
};

int main()
{

}