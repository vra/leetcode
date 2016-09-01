#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	
	  //TOO SLOW!!
    vector<vector<int>> threeSum(vector<int>& nums) {
		
		vector<vector<int>> result;
		vector<int> one_group;

		for (int i = 0; i < int(nums.size() - 2); ++i)
		{
			for (int j = i + 1; j < int(nums.size() - 1); ++j)
			{
				if (find(nums.begin()+j+1, nums.end(), - nums[i] - nums[j]) !=nums.end())
				{
					one_group.push_back(nums[i]); 
					one_group.push_back(nums[j]); 
					one_group.push_back(-nums[i]-nums[j]); 

					sort(one_group.begin(), one_group.end());
					//check if exist same set in result
					if (result.empty())
					{
						result.push_back(one_group);
					}
					else
					{

						bool hasSame = false;
						for (int k = 0; k < result.size(); ++k)
						{
							if (result[k] == one_group)
							{
								hasSame = true;
								break;
							}
					}
					if (!hasSame)
					{
						result.push_back(one_group);
					}
				}
				  one_group.clear();
			}
		} 
	}

	   return result;
    }
    //copy from here: https://discuss.leetcode.com/topic/8125/concise-o-n-2-java-solution/6
    vector<vector<int> > threeSum2(vector<int> &num) {
        vector<vector<int> > ans;
        int i, j, k, n = num.size();
        sort(num.begin(), num.begin() + n);
        for (i = 0; i < n; i++){
            if (i > 0 && num[i] == num[i - 1]) continue;
            k = n - 1;
            j = i + 1;
            while (j < k){
                if (num[i] + num[j] + num[k] > 0) k--;
                else if (num[i] + num[j] + num[k] < 0) j++;
                else{
                    vector<int> tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[j]);
                    tmp.push_back(num[k]);
                    ans.push_back(tmp);
                    while (j < k && num[k] == num[k - 1]) k--;
                    while (j < k && num[j] == num[j + 1]) j++;
                    k--; j++;
                }
            }
        }
        return ans;
    }
};


int main()
{
	Solution s = Solution();
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(-2);
	nums.push_back(1);
	nums.push_back(0);
//	nums.push_back(-1);
//	nums.push_back(-4);

	vector<vector<int>> result = s.threeSum(nums);

	return 0;
}
