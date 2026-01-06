//1482. Minimum Number of Days to Make m Bouquets
/*
 This problem is solved using Binary Search on the number of days.
 The minimum possible day is the smallest value in bloomDay[]
 and the maximum possible day is the largest value in bloomDay[].
 So our search space lies between [minDay, maxDay].

 For a given day 'mid', we check whether it is possible to make
 at least 'm' bouquets by that day.

 To check this, we iterate through the bloomDay array and count
 consecutive flowers that have bloomed (bloomDay[i] <= mid).
 Whenever we get 'k' consecutive bloomed flowers,
 we form one bouquet and reset the counter.

 If the number of bouquets formed is greater than or equal to 'm',
 then 'mid' is a valid answer.
 Since we want the minimum possible day, we try to search on the left side.

 If the number of bouquets formed is less than 'm',
 then 'mid' is not sufficient, so we move the search to the right.

 We use >= m instead of == m because even if we can form more bouquets,
 the condition is still satisfied and we only care about finding
 the minimum day on which the requirement is fulfilled.

*/
class Solution {
public:
    int bloom(int mid,vector<int> &bloomDay, int k, int n){
        int count=0,nob=0;
        for(int i=0;i<n;i++){
         if(bloomDay[i]<=mid){
          count++;
         }
         else{
           nob+=(count/k);
           count=0;
         }
        }
    nob+=(count/k);
    return nob;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
    long long val = m*1LL*k*1LL;
    int n=bloomDay.size();
    if(val>n)return -1;
    int mini=INT_MAX;
    int maxi=INT_MIN;
    int mid;
    for(int i=0;i<n;i++){
      mini=min(mini,bloomDay[i]);
      maxi=max(maxi,bloomDay[i]);
    }
    int low=mini;
    int high=maxi;
    int ans=0;
    while(low<=high){
    // mid=(low+high)/2;
    mid=low+(high-low)/2;
    if(bloom(mid,bloomDay,k,n)>=m){
        ans=mid;
        high=mid-1;
    }
    else{
        low=mid+1;
    }
    }
    return ans;
    }
};