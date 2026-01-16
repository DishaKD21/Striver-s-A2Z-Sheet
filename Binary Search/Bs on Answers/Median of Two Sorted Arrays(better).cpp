//4. Median of Two Sorted Arrays(better)
/*
In this problem we are given two sorted arrays nums1 and nums2.
We have to find the median of the combined sorted array,
but without actually creating a new merged array.

First, we calculate the total number of elements (cnt).
Based on this, we find the middle index positions:
- ind1 = (cnt - 1) / 2
- ind2 = cnt / 2

These represent the median positions in 0-based indexing.
For odd length, both point to the same middle element.
For even length, they point to the two middle elements.

We then use two pointers i and j to traverse nums1 and nums2
just like the merge step of merge sort.
Variable c keeps track of how many elements we have processed so far.

While both arrays have elements:
- We compare nums1[i] and nums2[j]
- The smaller value is considered next in the merged order
- When the current count c matches ind1 or ind2,
  we store that value in ele1 or ele2
- We move the corresponding pointer and increment c

After one array is exhausted, we continue processing the remaining
elements of the other array in the same way, still checking for
ind1 and ind2.

At the end:
- If total count is even, the median is the average of ele1 and ele2
- If total count is odd, the median is ele1

This approach works in O(n + m) time and O(1) extra space,
and avoids creating an extra merged array.
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int cnt = nums1.size() + nums2.size();
        int ind1 = (cnt - 1) / 2;
        int ind2 = cnt / 2;
        int ele1 = 0, ele2 = 0;
        int c = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                if (c == ind1) ele1 = nums1[i];
                if (c == ind2) ele2 = nums1[i];
                i++;
            } else {
                if (c == ind1) ele1 = nums2[j];
                if (c == ind2) ele2 = nums2[j];
                j++;
            }
            c++;
        }

        while (i < nums1.size()) {
            if (c == ind1) ele1 = nums1[i];
            if (c == ind2) ele2 = nums1[i];
            i++;
            c++;
        }

        while (j < nums2.size()) {
            if (c == ind1) ele1 = nums2[j];
            if (c == ind2) ele2 = nums2[j];
            j++;
            c++;
        }

        if (cnt % 2 == 0)
            return (ele1 + ele2) / 2.0;
        else
            return ele1;
    }
};