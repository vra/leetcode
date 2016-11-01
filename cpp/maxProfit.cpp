class Solution {
public:
    int maxProfit2(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        int left=0;
        int right=1;
        int res=0;
        while(right<prices.size()){
            res=max(res,prices[right]-prices[left]);
            if(prices[left]>prices[right])
                left=right;
            right++;
        }
        return res;
    }
    int maxProfit3(vector<int>& prices) {
    int maxPro = 0, minPrice = INT_MAX;
    for(int i = 0; i < prices.size(); i++) {
        minPrice = min(minPrice, prices[i]);
        maxPro = max(prices[i] - minPrice, maxPro);
    }
    return maxPro;
    }
    int maxProfit(vector<int>& prices) {
    int ret = 0, max = 0;
    for(int i = 1; i < prices.size(); i++)
    {
        ret += prices[i] - prices[i-1];
        if(ret < 0) ret = 0;
        if(ret > max) max = ret;
     }
     return max;
}
};
