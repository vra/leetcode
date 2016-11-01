class Solution {
public:
    int reverse(int x) {
    int symbol = 1;
	int remainder = 0;	//每次求模得到的每位上的数字

	vector<int> digital;

	//正负号判断
	if (x < 0)
	{
		symbol = -1;
	}
	
    int tmp = symbol * x;
    
	while (tmp > 0)
	{
		remainder = tmp % 10;
		tmp = (tmp - remainder) / 10;

		if (remainder == 0 && digital.size() == 0)
		{
			continue;
		}

		digital.push_back(remainder);
	}
	
	if (digital.size() > 10 || (digital.size() == 10 && digital[0] > 2))
	{
	    return 0;
	}
	
	long long u_result = 0;
	for (int i = 0;i < digital.size(); i++)
	{
		u_result += digital[i] * pow(10, digital.size() - i - 1);
	}

	if ( u_result > pow(2,31) - 1)
	{
		return 0;
	}

	int result = 0;
	for (int i = 0;i < digital.size(); i++)
	{
		result += digital[i] * pow(10, digital.size() - i - 1);
	}

	result = symbol * result;

	return result;
    }
};
