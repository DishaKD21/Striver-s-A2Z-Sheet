//Switch Case statement
/*very simple just applying switch case for choice whether the user
wantes to calculate the area of circle of area of rectangle */
class Solution {
  public:
    double switchCase(int choice, vector<double> &arr) {
        switch(choice){
            case 1: return M_PI*arr[0]*arr[0];
                   
            case 2: return arr[0]*arr[1];
                    
            default: return -1;
        }
        
    }
};