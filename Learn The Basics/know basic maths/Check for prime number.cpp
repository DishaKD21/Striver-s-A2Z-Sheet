//Check for prime number
class Solution {
  public:
    bool isPrime(int n) {
        if(n<=2){
            return false;
        }
        else{
         for(int i=2;i<n;i++){
             if((n%i)==0){
                 return false;
             }
         }
        }
        return true;
    }
};