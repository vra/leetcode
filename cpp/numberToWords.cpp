#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        
		if (num == 0)
		{
			return "Zero";
		}
		vector<int> shortNums;
		string words = "";

		const string unit[] ={""," Thousand", " Million", " Billion"};

		shortNums = splitNumber(num);

		for (int i =0; i < shortNums.size(); i++)
		{
			if (shortNums[i] != 0)
			{
				words = shortNumberToWords(shortNums[i]) +unit[i] +  words; 
				if (i < shortNums.size() -1 && shortNums[i + 1] != 0)
				{
					words = ' ' + words;
				}
			}

			else if (i > 0 && shortNums[i - 1] > 0)
			{
				words = ' ' + words;
			}
			
		}

		return words;
    }

	vector<int> splitNumber(int num){
		vector<int> shortNums;

		if (num == 0)
		{
			//If the size of shortNums is zero, then num is zero
			return shortNums;
		}

		while (num >= 1)
		{
			shortNums.push_back(num % 1000);
			num = num / 1000;
		}

		return shortNums;
	}

	string shortNumberToWords(int num)
	{
		string words = "";

		if (num == 0)
		{
			return words;
		}
		
		const char* numberWordsArray[]={
			"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
			"Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen",
			"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety","Hundred"};

		vector<string> numberWords(numberWordsArray, end(numberWordsArray));
		
		int bai = num / 100;
		if (bai >= 1)
		{
			words = words +numberWords[bai - 1] + ' ' + numberWords[numberWords.size() - 1];
		}

		int shi = (num / 10) % 10;
		int ge = num % 10;

		if (shi > 1)
		{
			if (bai != 0)
			{
				words = words + ' ';
			}

			words = words + numberWords[17 + shi];
			if (ge >= 1)
			{
				words = words + ' ' + numberWords[ge - 1]; 
			}
		}
		else if (shi == 1)
		{
			if (bai != 0)
			{
				words = words + ' ';
			}

			words = words + numberWords[9 + ge];
		}
		
		else
		{
			if (ge >=1)
			{
				if (bai != 0)
				{
					words = words + ' ';
				}
				words = words + numberWords[ge - 1];
			}
		}


		return words;
	}
	
};

