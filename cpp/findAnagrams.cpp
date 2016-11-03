#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	// Solution1: too slow
    vector<int> findAnagrams1(string s, string p) {
		vector<int> result;
		int s_len = s.size();
		int p_len = p.size();
		int i = 0;
		while (i < s_len)
		{
			int continue_num = 0;
			string tmp_p = p;
			while(tmp_p.end() !=find(tmp_p.begin(), tmp_p.end(), s[i]) && continue_num < p_len) {
				string::iterator pos = find(tmp_p.begin(), tmp_p.end(), s[i]);
				tmp_p.erase(pos-tmp_p.begin(), 1);
				
				++i;
				++continue_num;
			}
			if (continue_num == p_len){
				result.push_back(i-continue_num);
			}
			i -= (continue_num-1);
		}

		return result;
	}

	// Solution2: calculate the number of appearance of chars of p in s.
	vector<int> findAnagrams(string s, string p) {
        vector<int> pv(256,0), sv(256,0), res;
        if(s.size() < p.size())
           return res;
        for(int i = 0; i < p.size(); ++i)
        {
            ++pv[p[i]];
            ++sv[s[i]];
        }
        if(pv == sv)
           res.push_back(0);
        for(int i = p.size(); i < s.size(); ++i)
        {
            ++sv[s[i]];
            --sv[s[i-p.size()]];
            if(pv == sv)
               res.push_back(i-p.size()+1);
        }
        return res;
    }
};

int main() {
	Solution s = Solution();
	vector<int> r = s.findAnagrams("cbaebabacd", "abc");

	return 0;
}
