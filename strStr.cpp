#include <iostream>

using namespace std;


int strStr(char *haystack, char *needle)
{
	for (int i = 0; ; i++)
	{
		for (int j = 0; ; j++)
		{
			if (needle[j] == 0) return i;
			if (haystack[i + j] ==0) return -1;
			if (haystack[i + j] != needle[j]) break;

		}
	}
}


int main()
{
	char haystack[] ="abcde";
	char needle[] ="c";

	int a = strStr(haystack, needle);

	cout  << a;

	return 0;
}