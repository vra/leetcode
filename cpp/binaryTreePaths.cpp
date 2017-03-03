#include <iostream>
#include <string>
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
	void subPath(TreeNode* root,  vector<string>& result, string t) {
		if (!root->left && !root->right) {
			result.push_back(t);
			return;
		}
		if (root->left) subPath(root->left, result, t + "->" + to_string(root->left->val));
		if (root->right) subPath(root->right, result, t + "->" + to_string(root->right->val));
	}
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;
		if (!root) return result;
		subPath(root, result, to_string(root->val));
		return result;
    }
};

int main(int argc, char const *argv[])
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(5);

	Solution s;
	vector<string> result = s.binaryTreePaths(root);
	for (auto r : result) {
		cout << r << endl;
	}

	return 0;

}
