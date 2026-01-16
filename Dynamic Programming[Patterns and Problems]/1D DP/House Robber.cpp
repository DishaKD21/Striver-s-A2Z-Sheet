//198. House Robber
/*
Goal:
Find the maximum sum such that no two chosen elements are adjacent.

Core Thinking:
At every index, I face a choice:
- Skip the current house → take the best till previous index
- Rob the current house → add its value to the best till index-2
I always choose the maximum of these two.

DP Meaning:
dp[i] represents the maximum money I can rob from houses [0..i].

Transition:
Answer at i depends only on i-1 and i-2, not on the whole array.

Approaches Used:
1) Recursion:
   Try both choices at every index.
   Used only to understand the problem (exponential time).

2) Memoization:
   Store answers for each index to avoid recomputation.
   Converts recursion to linear time.

3) Tabulation:
   Build answers from left to right using the DP relation.

4) Space Optimization:
   Since only last two states are needed, I replace dp[] with two variables.
   One stores the best till previous index, the other till index-2.

Edge Handling:
- If there is only one house, rob it.
- If there are no houses, profit is zero.

Final Insight:
At every step, the problem reduces to choosing between
"rob this house and skip the previous"
or
"skip this house and take the previous best".

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int recursion(int i,vector<int> &nums){
     if(i==0) return nums[0];
     if(i<0) return 0;
      int left = 0 + recursion(i-1,nums);
      int right = nums[i] + recursion(i-2,nums);
      return max(left,right);
    }
    int memo(int i, vector<int> &nums, vector<int> &dp){
    if(i==0) return nums[0];
    if(i<0) return 0;
    if(dp[i]!=-1)return dp[i];
    int left = 0 +memo(i-1,nums,dp);
    int right = nums[i] + memo(i-2,nums,dp);
    return dp[i]=max(left,right);
    }
    int tabulation(vector<int> &nums, vector<int> &dp,int n){
    if(n==1)return nums[0];
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i=2;i<n;i++){
    int left = 0 + dp[i-1];
    int right = nums[i] + dp[i-2];
    dp[i]=max(left,right);    
    } 
    return dp[n-1];   
    }
    int spaceOptimized(vector<int> &nums,int n)
    {
    int prev,prev2,curr;
    if (n == 1) return nums[0];
    prev2 = nums[0];                 // dp[0]
    prev = max(nums[0], nums[1]);  //dp[1]
    for(int i=2;i<n;i++){
    int left = 0 + prev;
    int right = nums[i] + prev2;
    curr=max(left,right);
    prev2=prev; 
    prev=curr;   
    } 
    return prev;   
    }
   
    int rob(vector<int>& nums){
    int n=nums.size();
    vector<int> dp(n,-1);
    //return recursion(n-1,nums); 
    //return memo(n-1,nums,dp); 
    //return tabulation(nums,dp,n);
    return spaceOptimized(nums,n);
    }
};