class Solution {
private:
    vector<vector<int>> res;
public:
    void permute_help(vector<int> &nums,int begin) {
        if(begin >= nums.size()) return;
        permute_help(nums, begin+1);
        for(int i=0; i<begin; i++){
            swap(nums[i], nums[begin]);
            res.push_back(nums);
            permute_help(nums, begin+1);
            swap(nums[i], nums[begin]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        res.push_back(nums);
        permute_help(nums,1);
        return res;
    }
};
