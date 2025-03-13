// 94. Binary Tree Inorder Traversal (iterative)
/*
here root node we are pushing in stack till null value is not coming
we are keep going in the left side and keep pushing in stack when there is null
value comes then going in the else part and pops the values and pushing in
vector and go to the right and do the same for it and continue..
*/
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> inorder;
        TreeNode* node;
        node = root;
        while (true) {
            if (node != nullptr) {
                st.push(node);
                node = node->left;
            }
            else {
                if (st.empty() == true) {
                    break;
                }
                node = st.top();
                st.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;
    }
};