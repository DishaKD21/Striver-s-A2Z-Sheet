//54. Spiral Matrix
/*
we are declaring here points first in a matrix we are putting left  at 0
right at last top at 0 and bottom at last
here you can see if we want to move in spiral then we have to move for sides
first left to right
second top to bottom
third right to left
fourth bottom to top
and this continues untill top and left is <= bottom and right respectively
for bottom to top and right to left we are checking condition because of that case when there is no one of them is not there suppose we went till right to left and there is no bottom to top left 
then we have to end it 
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int left=0,right=n-1;
        int top=0,bottom=m-1;
        vector<int> ans;
        while(top<=bottom && left<=right){
        //left to right
        for(int i=left;i<=right;i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        //top to bottom
        for(int i=top;i<=bottom;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        //right to left
        if(bottom>=top){
         for(int i=right;i>=left;i--){
            ans.push_back(matrix[bottom][i]);
        }
        bottom--;
        }
        
        //bottom to top
        if(left<=right){
        for(int i=bottom;i>=top;i--){
            ans.push_back(matrix[i][left]);
        }
        left++;
        }
        
        }     
        return ans;
    }
};