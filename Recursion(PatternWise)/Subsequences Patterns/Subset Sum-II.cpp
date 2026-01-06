//90. Subsets II
/*
we will sort all the elements of vector sinsce its written in question that we don't want duplicates if we will not sort the array then set will take [1,4,4], [4,1,4] and [4,4,1] as three diff vectors we want to remove these duplication so we will sort nums first.

The logic is based on the "take and not take" approach (also called include/exclude recursion).
For every index `i`, we check if it is greater than or equal to the size of the input vector.
If it is, that means we have formed one complete subset, so we insert the current `vec` into the `s1` set. because we dont want to push duplicates inside the ans vector so we will not push those vectors which are already inside ans for that we are directly pushing vector inside set.

If it's not, we have two choices:
1. Take the current element (nums[i]) — push it into the `vec` and recursively call the function with the next index.
2. Not take the current element — don't push anything, just move to the next index with another recursive call.

At each step, we go deeper by branching into these two choices, generating all possible subsets.

*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> vec;
        set<vector<int>> s1;
        sort(nums.begin(), nums.end());
        int n = nums.size(), i = 0;
        f(i, nums, n, vec, s1);
        for (const auto& v : s1) {
            ans.push_back(v);
        }
        return ans;
    }
    void f(int i, vector<int>& nums, int n, vector<int>& vec,
           set<vector<int>>& s1) {
        if (i >= n) {
            s1.insert(vec);
            return;
        }
        vec.push_back(nums[i]);
        f(i + 1, nums, n, vec, s1);
        vec.pop_back();
        f(i + 1, nums, n, vec, s1);
        return;
    }
};