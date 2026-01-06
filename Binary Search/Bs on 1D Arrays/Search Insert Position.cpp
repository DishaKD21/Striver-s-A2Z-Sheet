//35. Search Insert Position
/*
Very simple explanation:

In this problem we have to find the index of the target in a sorted array.
If the target is not present, we return the index where it should be
inserted so that the array remains sorted.

We use binary search because the array is already sorted.

First, we take two pointers:
l at the beginning of the array and h at the end of the array.

In each step, we calculate the middle index (mid).
If nums[mid] is equal to the target, we immediately return mid.

If nums[mid] is smaller than the target, it means the target can only
be on the right side, so we move l to mid + 1.

If nums[mid] is greater than the target, it means the target can only
be on the left side, so we move h to mid - 1.

We continue this process until l becomes greater than h.
If the target is not found, the loop ends.

At the end of the binary search, l points to the exact position where
the target should be inserted to keep the array sorted.
So we return l.

This solution works in O(log n) time and uses O(1) extra space.
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;

        while (l <= h) {
            int mid = (l + h) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }
        return l;
    }
};
