#include <iostream>
#include <stdio.h>

#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
//copy from here: https://discuss.leetcode.com/topic/16754/simple-and-fast-c-c-with-explanation
int maxArea(vector<int>& height) {
    int water = 0;
    int i = 0, j = height.size() - 1;
    while (i < j) {
        int h = min(height[i], height[j]);
        water = max(water, (j - i) * h);
        while (height[i] <= h && i < j) i++;
        while (height[j] <= h && i < j) j--;
    }
    return water;
}
	int calArea(int i, int ai, int j ,int aj){
		printf("i:%d, ai: %d, j: %d, aj: %d\n", i, ai, j ,aj);
		return min(ai, aj) * abs(i - j);
	}
  //Two slow!
    int maxArea2(vector<int>& height) {
    	int currMaxArea = 0;
    	for (int i = 0; i < height.size(); ++i){
    		for (int j = 0; j < height.size(); ++j){
    			int currArea = calArea(i, height[i], j, height[j]);
    			cout << i << j << currArea << endl;
    			if ( currArea > currMaxArea){
    				currMaxArea = currArea; 
    			}	

    		}
    	}

    	return currMaxArea;
    }
};

int main(){
	vector<int> v;
	v.push_back(1);
	v.push_back(1);

	Solution s = Solution();
	int result = s.maxArea(v);
	cout << result << endl;

	return 0;
}
