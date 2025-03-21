//Bubble Sort
/*
in bubble sort 
we get maximum value and put it at end by swapping adjecent value
suppose array is ={20,9,45,34,2}
step 1: check if first value is bigger than the second one in this 
array 20 is bigger than 9 so we wil swap      
{9,20,45,34,2}
move forward check for sec and third element 
{9,20,45,34,2} no swap because 45 is bigger than 20
move forward
{9,20,34,45,2} swap 34 and 45
move forward
{9,20,34,2,45} swap because 45 is bigger than 2 when you check
through whole array once entirely you will see max element will reach at last 
Step 2: follow same process for remaining elements from 0 to n-2
step 3: this time 0 to n-3 
time complexity : O(n^2) worst caseor avg case and O(n) best case when array is given 
already sorted

*/

class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
    int n=arr.size();
    int swaphappned=0;
      for(int i=n-1;i>=0;i--){
         for(int j=0;j<i;j++){
           if(arr[j]>arr[j+1])  {
               swap(arr[j],arr[j+1]);
               swaphappned=1;
           }
         }
         if(swaphappned==0){
             break;
         }
         
      }
    }
};