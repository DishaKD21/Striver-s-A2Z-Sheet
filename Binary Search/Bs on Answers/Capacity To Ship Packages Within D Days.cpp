//1011. Capacity To Ship Packages Within D Days
// 1011. Capacity To Ship Packages Within D Days
/*
 In this problem, we need to find the minimum ship capacity such that
 all packages can be shipped within the given number of days.

 The important observation here is that:
 - If the ship capacity is increased, the number of days required
   to ship all packages will either decrease or remain the same.
 Because of this monotonic behavior, we can apply Binary Search
 on the answer (ship capacity).

 Search Space:
 - The minimum possible capacity is the maximum weight in the array,
   because the ship must be able to carry at least one package.
 - The maximum possible capacity is the sum of all weights,
   which means shipping all packages in one day.

 totaldays function:
 - This function simulates the shipping process for a given capacity.
 - We keep adding package weights to the current load.
 - If adding a package exceeds the capacity, we move to the next day
   and reset the load.
 - At the end, it returns the total number of days required
   for that capacity.

 Binary Search Logic:
 - We take a mid capacity and check how many days are needed.
 - If the required days are less than or equal to the given days,
   then this capacity is valid, and we try to find a smaller capacity
   by moving to the left.
 - If the required days are more than the given days,
   then the capacity is too small, so we move to the right.

 Finally, we return the minimum capacity that satisfies the condition.
*/

class Solution {
public:
    int totaldays(vector<int>& weights, int capacity, int n) {
        int day = 1, load = 0;
        for (int i = 0; i < n; i++) {
            if (load + weights[i] > capacity) {
                day++;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int mid, ans = 0;
        while (low <= high) {
            mid = (low + high) / 2;
            if (totaldays(weights, mid, n) <= days) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};