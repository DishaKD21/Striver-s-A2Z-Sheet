//145. Binary Tree Postorder Traversal(using 2-Stack)
/*
think first of all what is postordertraversal left right root correct?
here we are taking two stacks for achiving this output first we are storing root node in the st1
and till st1 dont get empty we are running the loop inside the loop we are going like we are poping 
first the root element and storing in the other stack(st2) and we are checking do root node have left
or right child then storing it in st1 each time root gets updated by top most of st1 and again that 
gets checked and continue until all of them are not checked 
and now if you see all the elements are forming postorder traversal in st2 one by one pooping element 
from st2 and storing it into vector and returning the postorder
*/
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder; 
        if(root == nullptr) return postorder;
        stack<TreeNode*> s1,s2;
        s1.push(root);
        while(!s1.empty()){
            root = s1.top();
            s1.pop();
            s2.push(root);
        if(root->left){
          s1.push(root->left);  
        }
        if(root->right){
          s1.push(root->right);  
        }
        }
        while(!s2.empty()){
            postorder.push_back(s2.top()->val);
            s2.pop();
        }
        return postorder;
    }
};
