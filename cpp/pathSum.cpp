#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int subPathSum(TreeNode* root, int target_sum) {
		if (!root || target_sum == 0) return 0;
		return (root->val == target_sum)  
			+subPathSum(root->left, target_sum -root->val)
			+subPathSum(root->right, target_sum-root->val);
	}

	int pathSum(TreeNode* root, int sum) {
		if (!root) return 0;
		return subPathSum(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};

main() {
	//[10,5,-3,3,2,null,11,3,-2,null,1]
	TreeNode* root = new TreeNode(10);
	root->left  = new TreeNode(5);
	root->right  = new TreeNode(-3);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(2);
//	root->left->right = new TreeNode(2);

	Solution s;
	cout <<  s.pathSum(root, 8);

	return 0;
}
