#include <iostream>
#include <vector>


using namespace std;

vector<int> plusOneAtEachDigit(vector<int>& digits, int pos)
{
	//最高位是9，则在最前面插入一位
	if (pos == 1 && digits[pos - 1] == 9)
	{
		digits[pos - 1] = 0;
		digits.insert(digits.begin(), 1);
		return digits;
	}

	if ( digits[pos - 1] < 9)
	 {
		 digits[pos - 1] = digits[pos - 1] + 1;
		 return digits;
	 }

	 //当前位是9
	 digits[pos -1] = 0;
	 digits = plusOneAtEachDigit(digits, pos - 1);
	 return digits;
	
}


 vector<int> plusOne(vector<int>& digits) 
{
	 return plusOneAtEachDigit(digits, digits.size());
}

int main()
{
	vector<int> d;
	d.push_back(7);
	d.push_back(9);

	d = plusOne(d);

	return 0;
}
