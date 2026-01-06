// 39. Combination Sum
/*
We are using recursion with the "take / not take" approach to generate
all possible combinations whose sum equals the target.

Idea:
- At every index `i`, we have two choices:
  1) Take the current element candidates[i]
     - Only if candidates[i] <= target
     - Since we can reuse the same element multiple times,
       we do NOT move to the next index (i remains same)
     - Reduce target by candidates[i]
  2) Not take the current element
     - Move to the next index (i + 1)
     - Target remains unchanged
    
Base Case:
- If i == n (we have considered all elements):
    - If target == 0 → current vector `vec` is a valid combination,
      so store it in `ans`
    - Otherwise, return without doing anything

Backtracking:
- After taking an element, we remove it from `vec` (pop_back)
  to explore other possible combinations.

This ensures:
- All unique combinations are generated
- Order does not matter
- Elements can be reused any number of times
*/

class Solution {
public:
    void f(int i, vector<int>& candidates, int n, vector<int>& vec,
           vector<vector<int>>& ans, int target) {
        if (i == n) {
            if (target == 0) {
                ans.push_back(vec);
                return;
            }
            return;
        }
        if (candidates[i] <= target) {
            vec.push_back(candidates[i]);
            f(i, candidates, n, vec, ans, target - candidates[i]);
            vec.pop_back();
        }
        f(i + 1, candidates, n, vec, ans, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> vec;
        int n = candidates.size(), i = 0;
        f(i, candidates, n, vec, ans, target);
        return ans;
    }
};
