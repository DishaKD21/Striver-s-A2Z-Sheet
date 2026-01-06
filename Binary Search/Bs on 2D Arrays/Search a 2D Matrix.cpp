//74. Search a 2D Matrix
/*
In this problem we are given a 2D matrix where each row is sorted
and also the first element of each row is greater than the last
element of the previous row. Because of this property, the whole
matrix can be treated like a single sorted 1D array.

First we take number of rows (m) and number of columns (n).
Total number of elements in the matrix is m * n. We apply
binary search on the range 0 to (m*n - 1) instead of doing
binary search row by row.

We use low and high as indices of this imaginary 1D array.
For any middle index (mid), we convert it into 2D coordinates.
Row index is calculated as mid / n and column index is calculated
as mid % n. This mapping helps us access the correct element
from the matrix.

Then we compare matrix[row][col] with the target.
If it is equal, we return true.
If the value is smaller than target, we move to the right side
by doing low = mid + 1.
If the value is greater than target, we move to the left side
by doing high = mid - 1.

We keep doing this until low becomes greater than high.
If the loop ends and we do not find the target, we return false.

This approach works in O(log(m*n)) time because we are using
binary search on all elements of the matrix.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m=matrix.size();
      int n=matrix[0].size();
      int row,col,mid;
      int low=0;
      int high=(m*n)-1;
      while(low<=high){
        mid=(low+high)/2;
        row=mid/n;
        col=mid%n;
        if(matrix[row][col] == target) return true;
        if(matrix[row][col]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
      } 
    return false;
    }
};