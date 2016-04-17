#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    string getHint(string secret, string guess) {
		int numOfBull = 0;
		int numOfCow = 0;

		bool *isBull = new bool[guess.size()];
		memset(isBull, 0, guess.size());

		bool *hasBeenFound = new bool[guess.size()];
		memset(hasBeenFound, 0, guess.size());

		for (int i = 0; i < guess.size(); ++i)
		{
			if (guess[i] == secret[i]) // find all Bulls
			{
				++numOfBull;
				isBull[i] = true;
			}
		}

		for (int i = 0; i < guess.size(); ++i)
		{
			if (!isBull[i])
			{
				for (int j = 0; j < secret.size() ; ++j) //Find all Cows
				{
					if (isBull[j])
					{
						continue;
					}

					if (!hasBeenFound[j] && guess[i] == secret[j])
					{
						++numOfCow;
						hasBeenFound[j] = true;
						break;	//Find one cow, then break, otherwise there will be duplicate
					} 
				}
			}
		}
       
		return to_string(numOfBull)+"A"+to_string(numOfCow)+"B";
    }
};

int main()
{
	string A("1122");
	string B("0001");

	Solution s = Solution();
	cout << s.getHint(A,B);

	return 0;
}