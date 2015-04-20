#include<iostream>

using namespace std;

 int lengthOfLastWord(string s) 
 {
	 int size = s.size();

	 //去掉尾部的空格
	 while (s[size - 1] == ' ')
	 {
		 size --;
	 }

	 int len = 0;
	 for (int i = size - 1; i >= 0; i--)
	 {
		 //遇到空格就停止
		 if (s[i] == ' ')
		 {
			 break;
		 }
		 else
		 {
			 len++;
		 }
	 }       

	 return len;
 }

int main()
{
	string s = "Hello World    ";
	int a = lengthOfLastWord(s);

	return 0;
}
