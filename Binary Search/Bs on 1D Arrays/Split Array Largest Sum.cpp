//410. Split Array Largest Sum
/*
In this problem we are given an integer array nums and an integer k.
We have to split the array into k non-empty contiguous subarrays such
that the largest sum among all subarrays is as small as possible.
Finally, we return this minimized largest sum.

This solution uses the same idea as the Book Allocation problem.
Here, each subarray is treated like the books assigned to one student,
and k represents the number of students. The sum of a subarray is the
total pages assigned to a student.

The key idea is to apply Binary Search on the answer instead of directly
trying all possible splits. The answer we are searching for is the
maximum allowed sum of any subarray.

First, we define a helper function countStudents. In the context of this
problem, this function checks how many subarrays are needed if we limit
the maximum sum of a subarray to a given value (limit). We traverse the
array from left to right and keep adding elements to the current subarray.
If adding the next element exceeds the limit, we start a new subarray.
By the end, the number of subarrays formed is returned.

In the main logic (allocateBooks), we define the binary search range.
The minimum possible value (low) is the maximum element in the array,
because a subarray must at least contain one element. The maximum
possible value (high) is the sum of all elements, which happens when
the whole array is taken as a single subarray.

We then perform binary search in this range. For a mid value, we check
how many subarrays are required if no subarray is allowed to have a sum
greater than mid. If the required number of subarrays is less than or
equal to k, it means this split is possible, so mid is a valid answer.
We store it and try to find a smaller value by moving the search to the
left. If more than k subarrays are needed, it means mid is too small, so
we move the search to the right.

This process continues until binary search ends. The stored answer is
the minimum possible value of the largest subarray sum.

The splitArray function simply calls this logic with nums as the array
and k as the number of subarrays.

Time complexity of this solution is O(n log(sum)), where n is the length
of the array, and space complexity is O(1).
*/

class Solution {
public:
    /*
    This function checks how many subarrays are needed
    if the maximum allowed sum of any subarray is 'limit'.

    We keep adding elements to the current subarray.
    If adding an element exceeds 'limit', we start a new subarray.
    */
    int countSubarrays(vector<int>& nums, int limit) {
        int subarrays = 1;   // at least one subarray
        int currentSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (currentSum + nums[i] > limit) {
                subarrays++;
                currentSum = nums[i];
            } else {
                currentSum += nums[i];
            }
        }
        return subarrays;
    }

    /*
    Main function for LeetCode 410:
    Split the array into k non-empty subarrays such that
    the largest subarray sum is minimized.
    */
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        // Binary search range
        int low = *max_element(nums.begin(), nums.end());   // minimum possible answer
        int high = accumulate(nums.begin(), nums.end(), 0); // maximum possible answer
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check how many subarrays are needed
            int requiredSubarrays = countSubarrays(nums, mid);

            if (requiredSubarrays <= k) {
                // mid is a valid answer, try smaller
                ans = mid;
                high = mid - 1;
            } else {
                // mid is too small, need larger sum
                low = mid + 1;
            }
        }
        return ans;
    }
};
