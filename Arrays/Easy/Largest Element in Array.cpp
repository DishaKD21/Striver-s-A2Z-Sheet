//Largest Element in Array
/*take one variable store the first value of array inside that and run
a loop through array to see if and bigger elemet exist than variable's 
value then replace that value with it return the variable value*/
class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
         int a=arr[0];
         for(int i=0;i<n;i++)
         {
             if(arr[i]>=a){
                 a=arr[i];
             }
         }
          return a;
    }
};

