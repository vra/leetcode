#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
		if (num < 1)
		{
			return false;
		}
		while (num != 1)
		{
			if (num % 2 == 0)
			{
				num /= 2;
			}
			else if (num % 3 == 0)
			{
				num /= 3;
			}
			else if (num % 5 == 0)
			{
				num /= 5;
			}
			else
			{
				return false;
			}
		}

		return true;
    }
	bool isUgly2(int num)
	{
		if (num < 1)
		{
			return false;
		}
		while (num != 1)
		{
			int tmp = num;
			if (num % 2 == 0)
			{
				num /= 2;
			}
			if (num % 3 == 0)
			{
				num /= 3;
			}
			if (num % 5 == 0)
			{
				num /= 5;
			}
			if (num == tmp)
			{
				return false;
			}
		}

		return true;
	}
	bool isUgly3(int num) 
	{
		for (int i=2; i<6 && num; i++)
		{
			while (num % i == 0)
			{
				num /= i;
			}
		}
    return num == 1;
    }
};

int main()
{
	Solution s = Solution();
	bool a = s.isUgly(14);
	bool a2 = s.isUgly(6);
	bool a3 = s.isUgly(8);
	bool a4 = s.isUgly(10);

	return 0;
}