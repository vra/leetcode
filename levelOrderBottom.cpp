#include <iostream>
#include < vector>

using namespace std;

struct TreeNode
{
	int val; 
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

void eachStep(vector<vector<int> >& res, TreeNode* node, int level)
{
	if (node == NULL)
	{
		return;
	}

	if (level == res.size())
	{
		res.push_back(vector<int>());
	}

	res[level].push_back(node->val);

	eachStep(res, node->left, level + 1);
	eachStep(res, node->right, level + 1);
}


vector<vector<int> > levelOrderBottom(TreeNode *root) 
{
	vector<vector<int> > res;
	
	eachStep(res, root, 0);

	return vector<vector<int> > (res.rbegin(), res.rend());
}

int main()
{
	TreeNode * root = new TreeNode(1);
	root->left = new TreeNode(3);
	root->right= new TreeNode(5);
	root->left->left= new TreeNode(7);
	root->right->left= new TreeNode(11);
	root->right->right= new TreeNode(13);

	vector<vector<int> > a = levelOrderBottom(root);

	return 0;
}
