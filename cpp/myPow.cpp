#include <iostream>
#include <cmath>

using namespace std;

class Solution {

public:
    double myPow(double x, int n) {
		if (x==0) return x;
		if (n < 0) return 1/x * myPow(1/x, -(n+1));
		if (n==0) return 1;
		if (n==1) return x;
		if (n==2) return x * x;

		if (n%2)
			return x*myPow(myPow(x, n/2),2);	
		else
			return myPow(myPow(x, n/2),2);	
    }
};

int main() {
	Solution s = Solution();
	cout<<  s.myPow(1.00000,2147483648) << endl;
	cout<<  s.myPow(1.00000,-2147483648) << endl;
	cout<<  s.myPow(0,0) << endl;
	cout<<  s.myPow(0,-1) << endl;
	cout<<  s.myPow(1,-2) << endl;
	cout<<  s.myPow(3,-20) << endl;
	cout<<  pow(3,-20) << endl;
	cout<<  s.myPow(1,-1) << endl;
	cout<<  s.myPow(1,0) << endl;
	cout<<  s.myPow(1,1) << endl;
	cout<<  s.myPow(1,99) << endl;
	cout<<  s.myPow(-1,1) << endl;
	cout<<  s.myPow(-1,0) << endl;
	cout<<  s.myPow(-1,100) << endl;
	cout<<  s.myPow(2,100) << endl;
	cout<<  s.myPow(10,100) << endl;
	cout<<  pow(10,100) << endl;
	cout<<  s.myPow(100,100) << endl;
	cout<<  pow(100,100) << endl;

	return 0;
}
