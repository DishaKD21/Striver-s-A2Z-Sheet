//1901. Find a Peak Element II
/*
In this problem we have to find a peak element in a 2D grid.
A peak element is an element which is strictly greater than its
left and right neighbors (and because of the way we choose it,
it will also be greater than its top and bottom neighbors).

The approach used here is Binary Search on columns.
Instead of checking every element of the matrix, we apply binary
search on the column index to reduce the time complexity.

For a chosen column (mid), we find the row index that contains
the maximum element in that column. This is done using the
findmax function, which scans all rows of that column and returns
the index of the row having the largest value.

Once we have the maximum element of the middle column, we compare
it with its left and right neighbors in the same row.
If the current element is greater than both left and right values,
then this element is a peak and we return its position.

If the left neighbor is greater than the current element, then a
peak must exist on the left side, so we move the binary search to
the left by setting high = mid - 1.

Otherwise, the right neighbor is greater, which means a peak lies
on the right side, so we move the binary search to the right by
setting low = mid + 1.
 
This process continues until we find a peak element.
The time complexity of this solution is O(n log m), where n is the
number of rows and m is the number of columns, and the space
complexity is O(1).
*/

class Solution {
public:
    int findmax(vector<vector<int>>& mat ,int n,int m,int col){
    int element=-1;
    int index=-1;
     for(int i=0;i<n;i++){
       if(element<mat[i][col]){
        element=mat[i][col];
        index=i;
       } 
     }
     return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
      int n=mat.size();
      int m=mat[0].size();
      int low=0;
      int high=m-1;
      int mid,left,right,maxrowElement;
      while(low<=high){
        mid=(low+high)/2;
        maxrowElement = findmax(mat,n,m,mid);
        left=(mid-1>=0)? mat[maxrowElement][mid-1]:-1;
        right=(mid+1<m)? mat[maxrowElement][mid+1]:-1;
        if(mat[maxrowElement][mid]>left && mat[maxrowElement][mid]>right)return {maxrowElement,mid};
        else if(mat[maxrowElement][mid]<left) {high=mid-1;}
        else {low=mid+1;}
      }
    return {-1,-1};
    }
};