//144. Binary Tree Iterative Preorder Traversal
// Here we are taking one stack and ,we are pushing the root node inside stack and then we are pushing the top value inside the vector named ans and then we are poping that value from the stack and we are checking if that node have right child then we will pushing it into stack and check if node have left child then we are pushin it again inside the stack and this process continues till stack is not empty once the stack is empty then we are returning the ans vector
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> ans;
      if(root==nullptr){
        return ans;
      }
      stack<TreeNode*> st;
      st.push(root);
      while(!st.empty()){
       root=st.top();
        st.pop();
        ans.push_back(root->val);
      if(root->right!=nullptr){
        st.push(root->right);
      }
      if(root->left!=nullptr){
       st.push(root->left);
      }
      }   
      return ans;
    }
};