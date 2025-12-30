
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