//216. Combination Sum III
/*
Problem:
We have to find all possible combinations of k numbers
from 1 to 9 such that their sum is equal to n.
Each number can be used only once.

Approach:
We use recursion with backtracking (take / not take approach).

Recursive Function f(i, vec, sum):
- `i` represents the current number we are considering (from 1 to 9)
- `vec` stores the current combination
- `sum` stores the sum of elements present in `vec`
- `k` is the required size of the combination
- `n` is the target sum

Base Case:
- If the size of `vec` becomes equal to k:
    - If sum == n → current combination is valid, store it in `ans`
    - Otherwise → discard this combination
  In both cases, return because we cannot add more elements.

Recursive Steps (for i ≤ 9):
1) Take the current number `i`
   - Add `i` to `vec`
   - Increase sum by `i`
   - Move to the next number: f(i + 1, ...)

2) Not take the current number `i`
   - Remove `i` from `vec` (backtracking)
   - Restore the sum
   - Move to the next number without taking `i`

Why backtracking?
- After exploring one choice, we undo changes (pop_back and sum restore)
  to explore other possible combinations.

Why i goes from 1 to 9?
- The problem restricts numbers to be between 1 and 9 only.
- Using i + 1 ensures each number is used only once.

This guarantees:
- Exactly k elements in each combination
- Sum equals n
- No duplicate combinations
*/

class Solution {
public:
    void f(int i, vector<vector<int>>& ans, vector<int>& vec, int k, int sum,int n) {
        if (vec.size() == k) {
            if(sum == n)
           { ans.push_back(vec);
            return;
            }
         else{
            return;
        }}
        if (i <= 9) {
            vec.push_back(i);
            sum = sum + i;
            f(i + 1, ans, vec, k, sum, n);
            vec.pop_back();
            sum = sum - i;
            f(i + 1, ans, vec, k, sum, n);
        }
        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> vec;
        f(1, ans, vec, k, 0, n);
        return ans;
    }
};