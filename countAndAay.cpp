/*思路：对每个字符串，分割成相同字符的序列，然后将相同字符的数目和字符写入到新
的字符串中
*/


#include <iostream>
#include<vector>

using namespace std;


string getNext(string s)
{
	vector<char> orderNums;	//保存每个序列的长度
	vector<char> diffChars;
	
	char currentChar = s[0];
	int currentNum  = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == currentChar)
		{
			currentNum++;
		}
		else
		{
			orderNums.push_back(currentNum + 48);
			currentNum = 1;
			diffChars.push_back(currentChar);
			currentChar = s[i];
		}
	}

	//把最后的数据保存起来
	orderNums.push_back(currentNum + 48);
	diffChars.push_back(currentChar);
	string res = string(orderNums.size() *2, ' ');
	for (int i = 0; i < orderNums.size(); i++)
	{
		res[2 * i] = orderNums[i];
		res[2 * i + 1] = diffChars[i];
	}

	return res;
}
string countAndSay(int n) 
{
	string curr = "1";
	for (int i = 0; i < n; i++)
	{
		curr = getNext(curr);
	}        

	return curr;
}

string countAndSay2(int n)
{
	if (n < 1) 
	{
		return "";
	}

	string result = "1";

	for (int i = 0; i < n - 1; i++)
	{
		int count = 1;
		string tmp = "";

		for (int j = 0; j < result.size() - 1; j++)
		{
			if (result[j + 1] == result[j])
			{
				count++;
			}
			else
			{
				tmp.push_back(char(count + '0'));
				tmp.push_back(result[j]);
				count = 1;
			}
		}
		tmp.push_back(char(count + '0'));
		tmp.push_back(result[result.size() - 1]);
		result = tmp;


	}

	return result;
}
int main()
{
	string a = countAndSay2(7);

	return 0;
}
