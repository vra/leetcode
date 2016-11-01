#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
		int numOfValues = nums.size();
		if (numOfValues < 2)
		{
			return 0;
		}
		int min = nums[0];
		int max = nums[0];

		/*1. find maximum and minimum*/
		for (int i= 0; i < numOfValues; i++)
		{
			if (min > nums[i])
			{
				min = nums[i];
			}
			if (max < nums[i])
			{
				max = nums[i];
			}
		}

		/*2. use vector of vector to store nums.*/
		float avgMargin  = float(max - min) / (numOfValues - 1);
		if (avgMargin == 0) //all values are same
		{
			return 0;
		}
		vector< vector<int> > buckets = vector< vector<int> >(numOfValues);

		for (int i = 0; i < numOfValues - 1; i++)
		{
			int idOfBucket = int((nums[i] - min) / avgMargin);
			buckets[idOfBucket].push_back(nums[i]);
		}
		buckets[numOfValues - 1].push_back(max);

		int prevMax = *max_element(buckets[0].begin(), buckets[0].end());
		int maxGap = 0;
		for (int i = 1; i < numOfValues; i++)
		{
			if (buckets[i].empty())
			{
				continue;
			}

			int currMin = *min_element(buckets[i].begin(), buckets[i].end());
			int currMax = *max_element(buckets[i].begin(), buckets[i].end());
			//the gap is current minimum minus previous maximum.
			int currGap = currMin - prevMax;
			if (maxGap < currGap)
			{
				maxGap = currGap;
			}

			prevMax = currMax;
		}

		return maxGap;
    }
};

int main()
{
	static const int arr[] = {15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,16790,10588,16521,6644,20880,15632,27078,25463,20124,15728,30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,7926,22101,32406,21540,31799,3768,26679,21799,23740};
	vector<int> nums (arr, arr + sizeof(arr) / sizeof(arr[0]));

	Solution s = Solution();
	int num = s.maximumGap(nums);
	cout << num << endl;

	return 0;
}