//73. Set Matrix Zeroes
/*
Here we have declared one vector of pair where we are checking through whole matrix that where the zero element is coming we are storing the index of that element in pair inside the vector 
now we get all the locations where 0 element is there  now we can see that we want to make that entire column and row zero here is how you can do it
here we can see that we can know which row or which column we have to make entirly zero by checking the location right
suppose we are getting zero at [1,1] index
then we know one thing that we have to make column 1 zero entirly and row 1 zero entirly
so, run a loop through pair of vector get the first element of pair and store it in i and then run loop for column starting from zero like that you will make zero entire row at the indexes
[1,0],[1,1],[1,2]
same for column also 
j=1 and loop will run through i this time 
[0,1],[1,1],[2,1]
skip those valuse where 0 is already there 
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      vector<pair<int,int>> a;
      int m=matrix.size();
      int n=matrix[0].size();
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(matrix[i][j]==0){
           a.push_back({i,j});
          }
        }
      }
    //   for (auto itr : a) {
    //         cout << "(" << itr.first << ", " << itr.second << ")" << endl;
    //     }

    for(auto it:a){
     int i=it.first;
     for(int j=0;j<n;j++){
      if(matrix[i][j]==0){
        continue;
      }
      matrix[i][j]=0; 
     }
    }   

    for(auto it:a){
     int j=it.second;
     for(int i=0;i<m;i++){
      if(matrix[i][j]==0){
        continue;
      }
      matrix[i][j]=0; 
     }
    }      
    }
};