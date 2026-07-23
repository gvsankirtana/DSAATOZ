class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //brute force solution TC->O(N^2) and SC->O(N^2)
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> ans(col, vector<int>(row));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                ans[j][(row-1)-i]=matrix[i][j];
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                matrix[i][j]=ans[i][j];
            }
        }
        //optimal solution TC->O(N^2) SC->O(1)
        //first transpose and then reverse
        for(int i=0;i<row-1;i++){
            for(int j=i+1;j<row;j++){
                int temp = matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for(int i=0;i<col;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
