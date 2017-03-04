#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int findRadiusLoop(vector<int>& houses, vector<int>& heaters) {

		int global_dist = 0;
		for (int i = 0; i < houses.size(); ++i) {
			int min_dist = INT_MAX;
			for (int j = 0; j < heaters.size(); ++j) {
				int curr_dist = abs(houses[i] - heaters[j]);
				if (curr_dist < global_dist) break;
				if (curr_dist < min_dist) {
					min_dist = curr_dist;
				}
			}

			if (min_dist > global_dist) {
				global_dist = min_dist;
			}
		}

		return global_dist;
    }

    int findRadiusNOTRIGHT(vector<int>& houses, vector<int>& heaters) {
		sort(heaters.begin(), heaters.end());
		int global_dist = 0;
		for (int i = 0; i < houses.size(); ++i) {
			int min_dist = INT_MAX;
			int j = 0;
			while (j < heaters.size() && heaters[j] < houses[i])
			{
				j++;
			}
			if (j == heaters.size()) {
				min_dist = abs(heaters[j-1] - houses[i]);
			} 
			else
			{
				min_dist = min(abs(heaters[j-1] - houses[i]), abs(heaters[j] - houses[i]));
			}

			if (min_dist > global_dist) {
				global_dist = min_dist;
			}
		}
		return global_dist;
	}
	int findRadius(vector<int>& houses, vector<int>& heaters) {
        if (heaters.size() == 0) {
            return 0;
        }
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int radius = 0;
        int index = 0;
        for (int i = 0; i < houses.size(); i++) {
            while (index + 1 < heaters.size() && (abs(heaters[index+1] - houses[i]) <= abs(heaters[index] - houses[i]))) {
                index++;
            }
            radius = max(radius, abs(heaters[index] - houses[i]));
        }
        return radius;
    }
};

int main() {
	Solution s;
	vector<int> houses = {1,2,3,4};
	vector<int> heaters = {1,4};

}
