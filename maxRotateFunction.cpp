//Question: https://leetcode.com/problems/rotate-function/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  
    //my function. too slow...
    int maxRotateFunction(vector<int>& A) {
		int n = A.size();
		int max;
		for (int i = 0; i < n; ++i){
			int sum = 0;
			for (int j = 0; j < n; ++j){
				sum += j * A[(n+j-i)%n];
			}
			if (i == 0){
				max = sum;
			}
			else if (sum > max){
				max = sum;
			}
		}
        
		return max;
    }
    //get from here: https://discuss.leetcode.com/topic/59980/my-o-n-simple-c-solution
    int maxRotateFunction2(vector<int>& A) {
        int F = 0, sum = 0, n = A.size();
        for (int i = 0; i < n; ++i){
            F += i * A[i];
            sum += A[i];
        }
        int m = F;
        for (int i = n - 1; i >= 0; --i){
            F = F + sum - n * A[i];
            m = max(m, F);
        }
        return m;
    }
};

int main(){
	Solution s = Solution();
	vector<int> A;
	A.push_back(-2147483648);
	A.push_back(-2147483648);

	int r = s.maxRotateFunction(A);

	return 0;
}
