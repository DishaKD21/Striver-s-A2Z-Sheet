//Subset Sums
/*
using same take not take approch and taking sum variable for storing sum of subset 
*/
class Solution {
  public:
    void f(int i,int n,vector<int> &arr,int sum,vector<int> &ans){
      if(i==n){
        ans.push_back(sum);
        return;
      }
      f(i+1,n,arr,sum,ans);
      f(i+1,n,arr,sum+arr[i],ans);
    }
    vector<int> subsetSums(vector<int>& arr) {
        int sum;
        vector<int> ans;
        int n=arr.size();
        f(0,n,arr,0,ans);
    return ans;
    }
};