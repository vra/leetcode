#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int v): val(v), left(NULL), right(NULL){}
};

int eachStep(TreeNode* root)
{
	if (root == NULL)
	{
		//任意设置一个非常大的数即可
		return 1000000;
	}

	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}

	return min(eachStep(root->left), eachStep(root->right)) + 1;
}
int minDepth(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return eachStep(root);
}

int minDepth2(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int left = minDepth2(root->left);
	int right = minDepth2(root->right);

	return (left == 0 || right == 0) ? left + right + 1 : min(left, right) + 1;
	
}

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(1);

	

	int a = minDepth2(root);


	return 0;
}
