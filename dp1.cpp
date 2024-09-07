Largest square formed in a matrix
Given a binary matrix mat of size n * m, find out the maximum length of a side of a square sub-matrix with all 1s.Input: n = 6, m = 5
mat = [[0, 1, 1, 0, 1], 
       [1, 1, 0, 1, 0],
       [0, 1, 1, 1, 0],
       [1, 1, 1, 1, 0],
       [1, 1, 1, 1, 1],
       [0, 0, 0, 0, 0]]
Output: 3
Explanation: 

The maximum length of a side of the square sub-matrix is 3 where every element is 1.
 Code in c++
1st Approach :-recursion
2nd approach - top down dp;
3rd approach-bottom up(tabulation)
4th approach-space optimization



class Solution {
    private:
    int solve(vector<vector<int>> mat,int i,int j,int &maxi){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        int right=solve(mat,i,j+1,maxi);
        int diagonal=solve(mat,i+1,j+1,maxi);
        int bottom=solve(mat,i+1,j,maxi);
        if(mat[i][j]==1){
            int ans=1+min(right,min(diagonal,bottom));
            maxi=max(maxi,ans);
            return ans;
        } 
        else{
            return 0;
        }
    }
    
    2nd Approach top-down
    
      int solve(vector<vector<int>> mat,int i,int j,int &maxi,
      vector<vector<int>>&dp){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int right=solve(mat,i,j+1,maxi,dp);
        int diagonal=solve(mat,i+1,j+1,maxi,dp);
        int bottom=solve(mat,i+1,j,maxi,dp);
        if(mat[i][j]==1){
          dp[i][j]=1+min(right,min(diagonal,bottom));
            maxi=max(maxi,dp[i][j]);
            return dp[i][j];
        } 
        else{
            return dp[i][j]=0;
        }
    }
    
    
    3rd approach
    
    int solveTab(vector<vector<int>> &mat,int &maxi){
        int r=mat.size();
        int c=mat[0].size();
        vector<vector<int>>dp(r+1,vector<int>(c+1,0));
            for(int i=r-1;i>=0;i--){
                for(int j=c-1;j>=0;j--){
                    int right=dp[i][j+1];
                    int diagonal=dp[i+1][j+1];
                    int bottom=dp[i+1][j];
                    if(mat[i][j]==1){
                        dp[i][j]=1+min(right,min(diagonal,bottom));
                        maxi=max(maxi,dp[i][j]);
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
            }
         return dp[0][0];
    }
    
    
    4th method- space optimization
    
    
     int solve(vector<vector<int>> &mat,int &maxi){
        int r=mat.size();
        int c=mat[0].size();
        // vector<vector<int>>dp(r+1,vector<int>(c+1,0));
        vector<int>curr(c+1,0);
        vector<int>next(c+1,0);
        
            for(int i=r-1;i>=0;i--){
                for(int j=c-1;j>=0;j--){
                    int right=curr[j+1];
                    int diagonal=next[j+1];
                    int bottom=next[j];
                    if(mat[i][j]==1){
                      curr[j]=1+min(right,min(diagonal,bottom));
                        maxi=max(maxi,curr[j]);
                    }
                    else{
                      curr[j]=0;
                    }
                }
                next=curr;
            }
         return next[0];
    }
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
      int maxi=0;
      solve(mat,0,0,maxi);
      return maxi;
    
    int maxi=0;
    vector<vector<int>>dp(n,vector<int>(m,-1));
    solve(mat,0,0,maxi,dp);
    return maxi;
    
    int maxi=0;
    solveTab(mat,maxi);
    return maxi;
    
    int maxi=0;
    solve(mat,maxi);
    return maxi;
    }
};
