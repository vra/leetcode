#include <iostream>
#include <stack>

using namespace std;

char getLeftPart(char ch)
{
	if (ch == ')')
	{
		return '(';
	}
	else if (ch == ']')
	{
		return '[';
	}
	else if (ch == '}')
	{
		return '{';
	}

	return '\0';
}
bool isValid(string s) 
{
	stack<char> stack;

	for (int i = 0; i < s.size(); i++)
	{
		switch (s[i])
		{
		case '(':
		case '[':
		case '{':
			stack.push(s[i]);
			break;
		case ')':
		case ']':
		case '}':
			if (stack.empty() || getLeftPart(s[i]) != stack.top())
			{
				return false;
			}
			else
			{
				stack.pop();
			}
		default:
			break;
		}
	}

	if (!stack.empty()) 
	{
		return false;
	}
	
	return true;
	      
}
