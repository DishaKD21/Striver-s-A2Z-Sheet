//Implement Upper Bound
/*
 UPPER BOUND means:
 → Find the index of the FIRST element in the array
   which is STRICTLY GREATER THAN the given target.

 Difference from Lower Bound:
 - Lower Bound  → first element >= target
 - Upper Bound  → first element > target

 Example:
 arr = [1, 2, 4, 4, 5]
 target = 4
 upper bound index = 4  (element 5)

 If no element > target exists,
 upper bound returns arr.size()
*/
class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int low=0;
        int high=arr.size()-1;
        int ans=arr.size(),mid;
        while(low<=high){
            mid=(low+high)/2;
            if(arr[mid]>target){
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
