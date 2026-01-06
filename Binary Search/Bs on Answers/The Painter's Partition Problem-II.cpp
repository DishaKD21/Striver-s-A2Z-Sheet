// The Painter's Partition Problem-II
/*
This problem is similar to the Book Allocation problem and
the Split Array Largest Sum problem.

We are given an array arr where each element represents the
length of a board. We are also given k painters.
Each painter can paint only contiguous boards and all painters
paint at the same speed.

We have to assign boards to painters such that:
- Each painter gets contiguous boards
- Every board is painted by exactly one painter
- The time taken is minimized

The time taken by a painter is the sum of board lengths assigned
to that painter. Our goal is to minimize the maximum time taken
by any painter.

We solve this using Binary Search on the answer.
*/

class Solution {
  public:
    
    /*
    This function checks how many painters are required
    if the maximum time allowed per painter is 'limit'.
    */
    int countPainters(vector<int>& arr, int limit) {
        int painters = 1;   // at least one painter
        int time = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (time + arr[i] > limit) {
                painters++;
                time = arr[i];
            } else {
                time += arr[i];
            }
        }
        return painters;
    }

    /*
    This function returns the minimum time required
    to paint all boards using k painters.
    */
    int minTime(vector<int>& arr, int k) {

        int n = arr.size();

        // Binary search range
        int low = *max_element(arr.begin(), arr.end());   // minimum possible time
        int high = accumulate(arr.begin(), arr.end(), 0); // maximum possible time
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check how many painters are needed
            int requiredPainters = countPainters(arr, mid);

            if (requiredPainters <= k) {
                // mid is a valid time, try to minimize it
                ans = mid;
                high = mid - 1;
            } else {
                // need more time per painter
                low = mid + 1;
            }
        }
        return ans;
    }
};
