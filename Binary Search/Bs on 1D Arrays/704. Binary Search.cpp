//704. Binary Search
/** 
#Intuition
Apply Simple Binary Search Inorder to find the index of the Target
# Approach
Taking,
l = for pointing lower index 
h = for pointing higher index
mid = for poining mid point of h and l ---> (l+h)/2
running while loop till l is less than of equal to h
each time it is checking the condition,
1.  If number at the lower index or higher index is equal to the target if yes then return that index 
2. If number at the mid point is lower than target then l will be mid+1 and h will remain as it is and again we will take the mid of l and h 
3. If number at the mid point is higher than target then h will be mid-1 and l will remain as it is and again we will take the mid of l and h 
4. In case of mid equal to target we will return mid 
return -1 if there is no number which is equal to the target

# Complexity
- Time complexity:
O(log n)

- Space complexity:
O(1)
**/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int h=nums.size()-1;
        int mid=(l+h)/2;
        while(l<=h){
            if(nums[l]==target){
                return l;
            }
            if(nums[h]==target){
                return h;
            }
            if(nums[mid]<target){
                l=mid+1;
                mid=(l+h)/2;
            }
            else if(nums[mid]>target){
                h=mid-1;
                mid=(l+h)/2;
            }
            else if(nums[mid]==target){
                return mid;
            }
        }
        return -1;
    }
};