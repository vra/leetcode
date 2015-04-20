#include <iostream>
#include <vector>

using namespace std;

string addBinary(string a, string b) 
{
	int size_a = a.size();
	int size_b = b.size();

    int shortLen = min(size_a, size_b);
	int longLen  = max(size_a, size_b);
	

	vector<char> chs;

	int back = 0;

	//对相同的位数进行操作
	for (int i = 0; i < shortLen; i++)
	{
		char c;
		int sum = (a[size_a -1 - i] - '0') + (b[size_b -1 - i] - '0') + back;

		c = sum % 2 + '0';
		back = sum /2;
		
		chs.push_back(c);
	}

	if (size_a < size_b)
	{
		for (int i = shortLen; i < longLen; i++)
		{
			char c;
			int sum = (b[size_b -1 - i] - '0') + back;

			c = sum % 2 + '0';
			back = sum /2;
		
			chs.push_back(c);
		}
	}

	
	//对不同的位数进行操作
	if (size_b < size_a)
	{
		for (int i = shortLen; i < longLen; i++)
		{
			char c;
			int sum = (a[size_a -1 - i] - '0') + back;

			c = sum % 2 + '0';
			back = sum /2;
		
			chs.push_back(c);
		}
	}


	//最前面增加一位
	if (back == 1)
	{
		chs.push_back('1');
	}

	string res = string(chs.size(), ' ');
	for (int i = 0; i < chs.size(); i++)
	{
		res[i] = chs[chs.size() - 1 -i];
	}
    
	return res;
}

string addBinary2(string a, string b) 
{
    string result = "";
    int apos = a.size() - 1;
    int bpos = b.size() - 1;
    int adigit, bdigit, carry = 0;

    while (apos >= 0 || bpos >= 0 || carry == 1)
    {
        adigit = bdigit = 0;

        if (apos >= 0) adigit = a[apos--] == '1';
        if (bpos >= 0) bdigit = b[bpos--] == '1';

        // Another way: the digit is 1 if adigit + bdigit + carry == 1 or == 3, but I noticed that
        // XOR is more concise:
        result = static_cast<char>(adigit ^ bdigit ^ carry + '0') + result; 
        carry = adigit + bdigit + carry >= 2;
    }

    return result;
}


int main()
{
	string a = "1010";
	string b = "1000";
	string res = addBinary(a, b);

	return 0;
}
