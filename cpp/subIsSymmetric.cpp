/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool subIsSymmetric(TreeNode* p, TreeNode* q) {
		if (!p && !q) return true;
		else if (!p || !q) return false;
		if (p->val != q->val) return false;
		return subIsSymmetric(p->left, q->right) && subIsSymmetric(p->right, q->left);
	} 
    bool isSymmetric(TreeNode* root) {
    	if (!root) return true;
    	return subIsSymmetric(root->left, root->right);
    }
};
