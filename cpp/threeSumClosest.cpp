class Solution {
    int target;
    int current = 0;
    int gap = 0;
    
    void cloestNum(int challenger){
        if(abs(challenger-target) < gap){
            current = challenger;
            gap = abs(challenger-target);
        }
    }
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if( nums.size() < 3 ){return 0;}
        int numsize = nums.size();
        sort(nums.begin(),nums.end());
        this->current = nums[numsize-3] + nums[numsize-2] + nums[numsize-1];
        this->gap = abs(this->current-target);
        this->target = target;
        
        for( int i = 0 ; i <= numsize-4 ; ++i){
            int initNum = nums[i];
            if ((i>0 && initNum == nums[i-1]) ) {
                continue;
            }
            int ptr1 = i+1;
            int ptr2 = numsize-1;
            
            
            int minsum = nums[i] + nums[i+1] + nums[i+2];
            int diff1 = minsum - target;
            if (diff1 >= 0) {
                if (abs(diff1) < gap) {
                    current = minsum;
                }
                break;
            }
            
            int maxsum = nums[i] + nums[numsize-2] + nums[numsize-1];
            int diff2 = target - maxsum;
            if (diff2 >= 0) {
                if (abs(diff2) < gap) {
                    current = maxsum;
                    gap = abs(diff2);
                }
                continue;
            }

            
            while(ptr1<ptr2){
                int sum = initNum + nums[ptr1] + nums[ptr2];
                cloestNum(sum);
                if(sum < target){
                    while (nums[ptr1] == nums[++ptr1]) {}
                }
                else if(sum > target){
                    while (nums[ptr2] == nums[--ptr2]) {}
                }
                else{
                    return target;
                }
            }
            
        }
        return this->current;
    }
};
