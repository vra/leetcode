 
Invert Binary Tree  C++ Non-recursive O(n) time O(1) space solution, based on Morris Traversal 
New users please read the instructions to format your code properly. Discuss is a place to post interview questions or share solutions / ask questions related to OJ problems. 

IMPORTANT: To sort the solutions by highest votes, you must login first.
0
A ayuanx 
Reputation:  20
Swap left child with right child when we officially leave current node in an in-order traversal.

68 / 68 test cases passed
Status: Accepted
Runtime: 0 ms

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode *t = root;
        while (t) {
            if (TreeNode *p = t->left) {
                while (p->left && p->left != t) p = p->left;
                if (p->left) {
                    p->left = NULL;
                    swap(t->left, t->right);
                    t = t->left;
                } else {
                    p = t->left;
                    while (p->right) p = p->right;
                    p->right = t;
                    t = t->left;
                }
            } else {
                swap(t->left, t->right);
                t = t->left;
            }
        }
        return root;
    }
};
