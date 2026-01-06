// Combination Sum II
/*
This problem is solved using recursion + backtracking.

Key Differences from Combination Sum I:
- Each number can be used ONLY ONCE.
- The input array may contain duplicates.
- The result must not contain duplicate combinations.

Approach:
1. First, we sort the candidates array.
   - Sorting helps in:
     a) Skipping duplicate elements
     b) Early stopping when current element > target

2. We use a recursive function `f(ind, target)`:
   - `ind` → starting index for the current recursion call
   - `target` → remaining sum to be achieved
   - `vec` → stores the current combination

Base Case:
- If target == 0:
  → Current combination is valid
  → Store it in `ans` and return

Recursive Loop:
- Iterate from index `ind` to end of array
- Skip duplicates:
  - If i > ind and candidates[i] == candidates[i-1],
    we continue to the next index to avoid duplicate combinations
- If candidates[i] > target:
  - Break the loop since array is sorted

Choices:
- Take the current element:
  - Add candidates[i] to `vec`
  - Recurse with:
      f(i + 1, target - candidates[i])
    (i + 1 ensures each element is used only once)
- Backtrack:
  - Remove the last element from `vec`

This guarantees:
- No duplicate combinations
- Each element is used at most once
- Only valid combinations summing to target are stored
*/

class Solution{
public:
    void f(int ind,int target, vector<int>& candidates, vector<int>& vec,
                          vector<vector<int>>& ans) {
        if (target==0){
        ans.push_back(vec);
        return;
        }
       for(int i=ind;i<candidates.size();i++){
        if(i>ind && candidates[i]==candidates[i-1])continue;
        if(candidates[i]>target)break;
        vec.push_back(candidates[i]);
        f(i+1,target-candidates[i],candidates,vec,ans);
        vec.pop_back();
       }
    } 
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> vec;
        int sum = 0;   
        sort(candidates.begin(),candidates.end());
        f(0,target,candidates,vec,ans);
        return ans;
    }     
};