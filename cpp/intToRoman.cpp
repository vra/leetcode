#include <iostream>
#include <string>
#include <vector>
#include <map>


using namespace std;

class Solution {
public:
    string intToRoman(int num) {
		map<int, char> unit_map;
		unit_map[1] = 'I';
		unit_map[5] = 'V';
		unit_map[10] = 'X';
		unit_map[50] = 'L';
		unit_map[100] = 'C';
		unit_map[500] = 'D';
		unit_map[1000] = 'M';

		string roman = "";
		int qian = num / 1000;
		int bai = num / 100 - 10 * qian;
		int shi = num / 10 - 100 * qian - 10 * bai;
		int ge = num % 10;

		vector<int> digits;
		digits.push_back(qian);
		digits.push_back(bai);
		digits.push_back(shi);
		digits.push_back(ge);
		vector<int> units;
		units.push_back(1000);
		units.push_back(100);
		units.push_back(10);
		units.push_back(1);

		while (qian != 0)
		{
			roman.push_back(unit_map[1000]);
			--qian;
		}

		for (int i = 1; i < digits.size(); ++i)
		{
			if (digits[i] != 0)
			{

				switch (digits[i])
				{
					case 0:
					case 1:
					case 2:
					case 3:
						while (digits[i] != 0)
						{
							roman.push_back(unit_map[1 * units[i]]);
							digits[i] = digits[i] - 1;
						}
						break;
					case 4:
						roman.push_back(unit_map[1 * units[i]]);
						roman.push_back(unit_map[5 * units[i]]);
						break;
					case 5:
						roman.push_back(unit_map[5 * units[i]]);
						break;
					case 6:
					case 7:
					case 8:
						roman.push_back(unit_map[5 * units[i]]);
						while (digits[i] != 5)
						{
							roman.push_back(unit_map[1 * units[i]]);
							digits[i] = digits[i] - 1;
						}
						break;
					case 9:
						roman.push_back(unit_map[1 * units[i]]);
						roman.push_back(unit_map[1 * units[i-1]]);
						break;
					default:
					break;
				}
			}
		}
		        
		return roman;
    }
};

int main()
{
	Solution s = Solution();

	cout << s.intToRoman(1001) << endl;

	return 0;
}


