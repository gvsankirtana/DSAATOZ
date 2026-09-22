class Solution {
    public int solve(int m, int n, int[][] dp) {
        if(m==1&&n==1) return 1;
        if(m<=0||n<=0) return 0;
        if(dp[m-1][n-1]!=-1){
            return dp[m-1][n-1];
        }
        int up = solve(m-1,n,dp);
        int left = solve(m,n-1,dp);
        return dp[m-1][n-1]=up+left;
    }
    public int uniquePaths(int m, int n) {
        //brute force TC->O(2^(m*n)) SC->O((m-1)+(n-1))
        if(m==1&&n==1){
            return 1;
        }
        if(m<=0||n<=0) return 0;
        int up = uniquePaths(m-1,n);
        int left = uniquePaths(m,n-1);
        return up+left;
        //optimal solution using DP TC->O(m*n) SC->O((m-1)+(n-1)) + O(m*n)
        int dp[][] = new int[m][n];
        for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
             dp[i][j] = -1;
        }
      }
        return solve(m,n,dp);
    //best optimal solution to opimize space SC->O(mXn) use tabulation bottom up
    int dp[][] = new int[m][n];
        for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
             dp[i][j] = 0;
        }
      }
      dp[0][0] = 1;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if (i > 0) dp[i][j] += dp[i-1][j];
            if (j > 0) dp[i][j] += dp[i][j-1];
        }
      }
      return dp[m-1][n-1];
    }
}
