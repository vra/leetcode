//Solve the problem https://leetcode.com/problems/island-perimeter/?tab=Description
class Solution {
public:
    int eachPerimeter(vector<vector<int>> &grid , int i, int j) {
		int count = 4;
		if (i-1>=0 && grid[i-1][j]) count--;
		if (i+1<grid.size() && grid[i+1][j]) count--;
		if (j-1>=0 && grid[i][j-1]) count--;
		if (j+1<grid[i].size()  && grid[i][j+1]) count--;

		return count;
	}

	int islandPerimeter(vector<vector<int>>& grid) {
		int permiter = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if (grid[i][j]) permiter += eachPerimeter(grid, i, j);
			}
		}

		return permiter;
    }

};
