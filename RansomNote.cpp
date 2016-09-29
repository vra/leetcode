//Question：https://leetcode.com/problems/ransom-note/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> charNum(26, 0);

		for (unsigned int i = 0; i < magazine.size(); ++i){
			++charNum[magazine[i] - 'a']; 
		}
		for (unsigned int i = 0; i < ransomNote.size(); ++i){
			if(--charNum[ransomNote[i] - 'a'] < 0){
				return false;
			}
		}
		return true;
    }
};
