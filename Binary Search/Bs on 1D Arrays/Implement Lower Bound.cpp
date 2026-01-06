//Implement Lower Bound
/*
 LOWER BOUND means:
 → Find the index of the FIRST element in the array
   which is GREATER THAN OR EQUAL TO the given target.

 Example:
 arr = [1, 2, 4, 4, 5]
 target = 4
 lower bound index = 2  (first 4)

 If target does NOT exist,
 lower bound gives the position where it can be inserted.
*/
class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int low=0;
        int high=arr.size()-1;
        int ans=arr.size(),mid;
        while(low<=high){
            mid=(low+high)/2;
            if(arr[mid]>=target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
       return ans; 
    }
};
