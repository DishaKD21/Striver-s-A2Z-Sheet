//240. Search a 2D Matrix II
/*
In this problem we are given a 2D matrix where:
- Each row is sorted from left to right
- Each column is sorted from top to bottom

Because of this special property, we can use a smart searching approach
instead of applying binary search on every row or column.

We start from the TOP-RIGHT corner of the matrix.
That position is chosen because:
- If the current value is greater than the target,
  then all values below it in the same column will also be greater,
  so we move LEFT.
- If the current value is smaller than the target,
  then all values on the left in the same row will be smaller,
  so we move DOWN.

We initialize:
- row = 0  (first row)
- col = n - 1 (last column)

Now we keep checking until we are inside the matrix:
- If matrix[row][col] is equal to target, we return true
- If matrix[row][col] is greater than target,
  we move left by doing col--
- If matrix[row][col] is smaller than target,
  we move down by doing row++

This way, in every step, we eliminate one full row or one full column.
If we move out of the matrix and do not find the target, we return false.

This approach works in O(m + n) time and is more efficient than
checking every element of the matrix.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m=matrix.size();
    int n=matrix[0].size();
    int row=0;
    int col=n-1;
    while(row<m && col>=0){
    if(matrix[row][col]==target) return true;
    else if(matrix[row][col]>target) col--;
    else if(matrix[row][col]<target) row++;
    } 
    return false;
    }
};