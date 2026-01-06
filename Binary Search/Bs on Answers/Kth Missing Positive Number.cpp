 //1539. Kth Missing Positive Number
/*
 We are given a sorted array of positive integers.
 We need to find the k-th missing positive number.

 Key Observation:
 In an ideal array with no missing numbers,
 the value at index i should be (i + 1).

 If arr[i] > (i + 1), then some numbers are missing before index i.

 Number of missing numbers before index i:
 missing = arr[i] - (i + 1)

 Example:
 arr = [2, 3, 4, 7, 11]
 index = 3 → arr[3] = 7
 missing = 7 - (3 + 1) = 3
 Missing numbers are: 1, 5, 6

 Since missing count increases as index increases,
 this function is monotonic, so we can apply Binary Search.

 Binary Search Logic:
 - If missing < k, it means the k-th missing number
   lies on the right side, so move low = mid + 1.
 - If missing >= k, it means we have crossed or reached
   the k-th missing number, so move high = mid - 1.

 After binary search ends:
 - low points to the first index where missing >= k.
 - high points to the last index where missing < k.

 Derivation of Answer:
 missing = arr[high] - (high + 1)
 Remaining missing numbers needed = k - missing
 Answer = arr[high] + (k - missing)

 Substituting missing:
 Answer = arr[high] + k - (arr[high] - (high + 1))
 Answer = high + 1 + k

 Since low = high + 1 after binary search,
 Final Answer = low + k

 Time Complexity: O(log n)
 Space Complexity: O(1)

*/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
     int low=0;
     int high=arr.size()-1;
     int mid,missing;
     while(low<=high){
        mid=(low+high)/2;
        missing = arr[mid]-(mid+1);
        if(missing<k){
           low = mid+1;
        }
        else{
            high= mid-1;
        }
     }

// ans -> arr[high]+more -> k-missing  --> missing=(arr[high]-(high+1))
// arr[high] +k - (arr[high]-(high+1))
// arr[high] +k - arr[high]+ high +1
// high+1+k
// low+k
     return low+k; 
    }
};