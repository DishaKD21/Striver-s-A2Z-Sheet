//104. Maximum Depth of Binary Tree(recursive)
// we will go to the left side and measure the hight and we will go to the right side and we will measure the height and we will check which one is bigger in them then we will take bigger one and add one in it that will be our depth of the tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return 1 + max(lh, rh);
    }
};