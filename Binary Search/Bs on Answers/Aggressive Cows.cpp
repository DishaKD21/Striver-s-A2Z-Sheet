// Aggressive Cows
/*
In this problem we are given positions of stalls and a number k,
which represents the number of cows. We have to place all k cows
in these stalls such that the minimum distance between any two
cows is as large as possible. This means we want to maximize the
minimum distance between cows.

First, we sort the stalls array because cows must be placed in
order of stall positions to correctly calculate distances.

The main idea is to use Binary Search on the answer (the distance).
The minimum possible distance (low) is 0, and the maximum possible
distance (high) is the distance between the first and last stall.

For a chosen distance (mid), we check whether it is possible to
place all k cows such that the distance between any two cows is at
least mid. This checking is done using the placecows function.

In the placecows function, we place the first cow in the first stall.
Then we iterate through the remaining stalls and place a cow whenever
the distance between the current stall and the last placed cow is
greater than or equal to the given distance. We keep counting how
many cows are placed. If we can place at least k cows, then this
distance is possible.

Back in the aggressiveCows function, if placing cows with distance
mid is possible, then we store mid as a possible answer and try to
find a larger minimum distance by moving the binary search to the
right (low = mid + 1). If it is not possible, we reduce the distance
by moving the binary search to the left (high = mid - 1).

This process continues until the binary search ends. The final
answer stored is the maximum possible minimum distance between
any two cows.

The time complexity of this solution is O(n log n) due to sorting
and binary search, and the space complexity is O(1).
*/

class Solution {
  public:
    bool placecows(vector<int> &stalls,int k,int distance){
       int countcows=1; 
       int last=stalls[0];
       for(int i=1;i<stalls.size();i++){
           if(stalls[i]-last>=distance){
               countcows++;
               last=stalls[i];
           }
           else{
             continue;   
           }
       }
       if(countcows>=k)return true;
       return false;
        
    }
    int aggressiveCows(vector<int> &stalls, int k) {
      sort(stalls.begin(),stalls.end());
      int ans=0;
      int low=0;
      int mid;
      int high=stalls[stalls.size()-1]-stalls[0];
      while(low<=high){
        mid=(low+high)/2;
        if(placecows(stalls,k,mid)==true){
         ans=mid;
         low=mid+1;
        }
        else{
          high=mid-1;
        }
      }
      return ans;
    }
};