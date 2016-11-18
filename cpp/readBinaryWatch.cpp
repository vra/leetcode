class Solution {
private:
    int onecnt(int num)
    {
        int ret = 0;
        while(num)
        {
            num = num & (num - 1);
            ret++;
        }
        return ret;
    }
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ret;
        for (int h = 0; h < 12; h++)
        {
            for (int m = 0; m < 60; m++)
            {
                if (onecnt(h) + onecnt(m) == num)
                {
                    stringstream tmp;
                    tmp << h << ":" << m / 10 << m % 10;
                    ret.push_back(tmp.str());
                }
            }
        }
        return ret;
    }
};
