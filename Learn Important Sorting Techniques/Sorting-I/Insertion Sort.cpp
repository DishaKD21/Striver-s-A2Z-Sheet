//Insertion Sort
/*
find minimum and plac it at it's right place 
suppose arr={20,9,45,34,2} 
step 1: taking first element as array of size 1 so in array of 
size one with one element we take that 20 is at its right place
Step 2: taking sec element as array of size 2 here we see 9 is not at its right place 
so we swap 20 and 9 
{[9,20],45,34,2}
step 3: taking next element as array of size 3, 45 is at its right place so no swapping
{[9,20,45],34,2}
step 4: taking next element as array of size 4 ,34 is not at its right place 
so we will shift it to the left untill it reaches to it's right place
{[9,20,34,45]}
step 5: taking next element as array of size 5 ,2 is not at it's right place 
so we will shift it to the left untill it reaches to it's right place
{[2,9,20,34,45]}
*/
class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        int n=arr.size();
        int j;
        for(int i=0;i<=n-1;i++){
            j=i;
            while(j>=0 && arr[j-1]>arr[j]){
               swap(arr[j],arr[j-1]);
               j--;
            }
        }   
    }
};