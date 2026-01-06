//Row with max 1s
/*

PROBLEM:
 - We are given a binary matrix (only 0s and 1s)
 - Each row is sorted (all 0s come first, then all 1s)
 - We have to find the index of the row that contains the maximum number of 1s

IDEA:
 - Since each row is sorted, all 1s start from a certain index
 - If we find the index of the FIRST 1 in a row,
   then number of 1s = (total columns - index of first 1)
 - To find the first 1 efficiently, we use Binary Search (lower bound)

TIME COMPLEXITY:
 - lowerbound for one row → O(log M)
 - For N rows → O(N log M)

*/
class Solution {
  public:
    int lowerbound(vector<int> &arr ,int x){
        int low=0;
        int high=arr.size()-1;
        int ans=arr.size(),mid;
        while(low<=high){
            mid=(low+high)/2;
            if(arr[mid]>=x){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
       return ans; 
    }
    int rowWithMax1s(vector<vector<int>> &arr) {
    int maxcount=0;
    int index=0;
       for(int i=0;i<arr.size();i++){
           int count1=arr[i].size()-lowerbound(arr[i],1);
           if(count1>maxcount){
              maxcount=count1;
              index=i;
           }
       }
       return index;
    }
};