class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int len1 = nums1.size();
        int len2 = nums2.size();
        int i = 0;
        int j = 0;
        while(i<len1 && j<len2){
            if(nums1[i]==nums2[j]){
                if(result.size()==0 || result[result.size()-1]!=nums1[i]){ 
                    result.push_back(nums1[i]); 
                }
                i++; 
                j++;
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else{ 
                i++;
            }
        }
        return result;
    }
};
