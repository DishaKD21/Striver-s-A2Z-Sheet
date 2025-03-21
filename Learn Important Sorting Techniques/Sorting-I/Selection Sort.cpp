//Selection Sort
/*
find the min and swap with the value which we asumed at min index         
*/
class Solution {
  public:
    void selectionSort(vector<int> &arr) {
        int min;
        int n=arr.size();
       for(int i=0;i<=n-2;i++){
           min=i;
        for(int j=i;j<=n-1;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(arr[min],arr[i]);
       }
    }
};