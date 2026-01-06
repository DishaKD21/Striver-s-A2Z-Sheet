//162. Find Peak Element
/*
First, we initialize the search space to cover the full array.
That means we set the left pointer to the first index and the
right pointer to the last index.

Then, we find the middle index of the current search space.
At this middle index, we compare the element with its right neighbor.

If the middle element is greater than its right neighbor, it means
the array is going down at this point, so a peak must exist on the
left side of the array, including the middle element itself.
In this case, we shrink the search space by moving the right pointer
to the middle index.

If the middle element is not greater than its right neighbor, it means
the array is going up, so a peak must exist on the right side of the
array. In this case, we move the left pointer to mid + 1.

We keep repeating this process until the left and right pointers
meet at a single index.

This final index is the position of a peak element in the array.
The time complexity of this approach is O(log n).
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       int low=0;
       int high=nums.size()-1;
       int left,right,mid;
       while(low<=high){
        mid=(low+high)/2;
        left  = (mid - 1 >= 0) ? nums[mid - 1] : INT_MIN;
        right = (mid + 1 < nums.size()) ? nums[mid + 1] : INT_MIN;
        if(nums[mid]>left && nums[mid]>right)return mid;
        else if(nums[mid]<left)high=mid-1;
        else low=mid+1;
       } 
     return 0;
    }
};