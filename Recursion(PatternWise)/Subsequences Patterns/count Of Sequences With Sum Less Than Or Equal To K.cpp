//  Count of Subsequences with sum less than or equal to K
/* This program generates all subsequences of an array using recursion.
 At each index, we have two choices: include the current element or exclude it.

 'vec' stores the current subsequence being formed.
 'sum' stores the sum of elements in the current subsequence.
 'k' is the maximum allowed sum.

When we reach the end of the array (i == n):
  - If sum <= k, the subsequence is valid.
  - We print the subsequence and count it.

Backtracking is used by removing the last element
so that the next recursive call starts correctly.

 The function returns the total count of subsequences
 whose sum is less than or equal to k.
*/
// vs code sol
#include <bits/stdc++.h>
using namespace std;
int f(int i, int arr[], int n, vector<int> &vec,int sum ,int k)
{  
    if (i >= n){
    if(sum<=k) 
    { for(int i=0;i<vec.size();i++){
             cout << vec[i]<<" ";
     }
      cout<<endl;
     return 1;
    }  
    return 0;
    }
    vec.push_back(arr[i]);
    sum+=arr[i];
    int l=f(i + 1, arr, n, vec ,sum ,k);
    vec.pop_back();
    sum-=arr[i];
    int r=f(i + 1, arr, n, vec,sum,k);
    return l+r;
}
int main()
{
    int ans;
    vector<int> vec;
    int n = 4, i = 0;
    int sum=0,k=10;
    int arr[n] = {3,3,6,8};
    ans = f(i, arr, n, vec,sum ,k);
    cout <<ans-1;
}