class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        priority_queue<int, vector<int>, greater<int>> gq(g.begin(), g.end());
        priority_queue<int, vector<int>, greater<int>> sq(s.begin(), s.end());
        int res;
        while(!sq.empty() && !gq.empty())
        {
            if (sq.top()>=gq.top())
            {
                sq.pop();
                gq.pop();
                res++;
            }
            else
            {
                sq.pop();
            }
        }

        return res;
    }
};
