#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int v) : val(v), left(NULL), right(NULL){}
};

bool hasPathSum(TreeNode* root, int sum)
{
	if (root == NULL)
	{
		return false;
	}
	
	if (root->val == sum && root->left == NULL && root->right == NULL)
	{
		return true;
	}

	{
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}

}


 int main()
 {
	 TreeNode* root = new TreeNode(-2);
	 root->right = new TreeNode(-3);

	 bool a = hasPathSum(root, -5);

	 return 0;
 }
