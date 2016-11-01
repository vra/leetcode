//Refer here: https://discuss.leetcode.com/topic/50315/a-summary-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently
class Solution {
public:
    int getSum(int a, int b) {
         return b==0? a:getSum(a^b, (a&b)<<1); //be careful about the terminating condition;
    }
};
