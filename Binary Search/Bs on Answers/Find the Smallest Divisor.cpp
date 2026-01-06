//1283. Find the Smallest Divisor Given a Threshold
/*
 Problem: Find the smallest divisor such that the sum of
 ceil(nums[i] / divisor) for all elements is <= threshold.

 Observation:
 As the divisor increases, the value of ceil(nums[i] / divisor)
 decreases, so the total sum is a monotonic (non-increasing) function.
 This monotonic behavior allows us to apply Binary Search.

 Approach:
 1. The smallest possible divisor is 1.
 2. The largest possible divisor is the maximum element in the array
    (dividing by anything larger gives the same or smaller result).

 For a chosen divisor 'mid':
 - We compute the sum of ceil(nums[i] / mid) for all elements.
 - If this sum is <= threshold, then 'mid' is a valid divisor,
   and we try to find a smaller valid divisor (search left).
 - If the sum is > threshold, then 'mid' is too small,
   so we need a larger divisor (search right).

 We keep updating the answer whenever we find a valid divisor,
 and finally return the minimum divisor that satisfies the condition.

*/
class Solution {
public:
    int divsum(vector<int> &nums, int div){
    int sum=0;
      for(int i=0;i<nums.size();i++){
        sum += ceil(((double)nums[i])/((double)div));
      } 
      return sum; 
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
    //  if(nums.size()>threshold) return -1;
     int low=1;
     int high=*max_element(nums.begin(),nums.end());
     int mid;
     int ans=0;
     while(low<=high){
        mid=(low+high)/2;
        if(divsum(nums,mid)<=threshold){
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