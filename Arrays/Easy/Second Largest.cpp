//Second Largest
/* 
first declare two variables assign both of them as minimum 
value which is lower than given limit here limit starts from zero so we are taking -1 
and run a loop through whole array if you find element larger than larget then store 
the value of largest element inside the second largest else  check if there is any 
element exist bigger from sec largest and smaller from largest then store it
and return the sec largest
*/

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
       int seclargest=-1;
       int largest=-1;
       for(int i=0;i<arr.size();i++){
           if(arr[i]>largest){
             seclargest=largest;
             largest=arr[i];
           }
           else if(arr[i]>seclargest && arr[i]<largest){
               seclargest=arr[i];
           }
       }
        return seclargest;
       }
};