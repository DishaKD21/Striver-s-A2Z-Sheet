//104. Maximum Depth of Binary Tree(iterative)
// here we are finding the number of levels in binary tree using BFS
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
    int maxDepth(TreeNode* root) {
    if(!root){
        return 0;
    }
    queue<TreeNode*> q;
     q.push(root);
     int level=0;
     while(!q.empty()){
        int s=q.size(); 
        for(int i=0;i<s;i++){      
        TreeNode *node=q.front();
        q.pop();
         if(node->left) {
          q.push(node->left);
         }  
         if(node->right) {
          q.push(node->right);
         }        
        }
        level++; 
     }
       return level;
    }
};