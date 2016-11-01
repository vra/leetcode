#include <iostream>

using namespace std;

class Solution{
	public:
	int arrangeCoins(int n){
		if (n < 2) return n;
		int curr_layer = 1;
		int left_item = n - 1;
		while(left_item >= curr_layer + 1){
			++curr_layer;
			left_item -= curr_layer;
		}

		return curr_layer;
	}
};


int main(){
	Solution s = Solution();
	//int r = s.arrangeCoins(10);
	int r = s.arrangeCoins(0+5);
	int r2 = s.arrangeCoins(1+5);
	int r3 = s.arrangeCoins(2+5);
	int r4 = s.arrangeCoins(3+5);
	int r5 = s.arrangeCoins(4+5);
	int r6 = s.arrangeCoins(5050);
	cout << r << endl;
	cout << r2 << endl;
	cout << r3 << endl;
	cout << r4 << endl;
	cout << r5 << endl;
	cout << r6 << endl;
}
