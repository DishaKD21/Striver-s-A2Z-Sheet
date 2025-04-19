//102. Binary Tree Level Order Traversal
// here we are pushing root node into the queue we are iterating inside the queue and each time we are running the loop till queue's size, taking queue's top and checking whether it is having left child and right then we are pushing it into the queue and when queue gets empty after iteration then we are poping that top value and storing it into the vector and continues the process at last when queue gets empty then we exit the loop and then we return vector of vectors named ans
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
    vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root==nullptr){
        return ans;
        }
    queue<TreeNode*> q;
    q.push(root);
     while(!q.empty()){
        int size=q.size();
        vector<int> v1; 
        for(int i=0;i<size;i++){
        TreeNode* node=q.front();
        q.pop();
         v1.push_back(node->val);
        if(node->left!=nullptr){
            q.push(node->left);
        }
        if(node->right!=nullptr){
            q.push(node->right);
        }
        }
        ans.push_back(v1);
     }
     return ans;
    }
};