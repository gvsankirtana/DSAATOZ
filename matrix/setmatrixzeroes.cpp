class Solution {
public:
   //brute force
    void mark_row(int i,int cols,vector<vector<int>>& matrix){
       for(int j=0;j<cols;j++){
        if(matrix[i][j]!=0){
            matrix[i][j]=-1;
        }
       }
    }
    void mark_col(int j,int rows,vector<vector<int>>& matrix){
    for(int i=0;i<rows;i++){
        if(matrix[i][j]!=0){
            matrix[i][j]=-1;
        }
    }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        //brute force use 3 loops and O(N^3) time comlexity
        int rows = matrix.size();              
        int cols = matrix[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                mark_row(i,cols,matrix);
                mark_col(j,rows,matrix);
                }
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==-1){
                    matrix[i][j]=0;
                }
            }
        }
        //better solution TC->O(NXM) SC->O(N)
        vector<bool> zeroRow(rows, false);
        vector<bool> zeroCol(cols, false);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    zeroRow[i]=true;
                    zeroCol[j]=true;
                }
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(zeroRow[i]||zeroCol[j]){
                    matrix[i][j]=0;
                }
            }
        } 
        //optimal solution O(NXM) SC->O(1)
        int col0=1;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j!=0){
                        matrix[0][j]=0;
                    }
                    else{
                        col0=0;
                    }
                }
            }
        }
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(matrix[i][j]!=0){
                    if(matrix[i][0]==0||matrix[0][j]==0){
                        matrix[i][j]=0;
                    }
                }
            }
        }
        if(matrix[0][0]==0){
            for(int j=0;j<cols;j++){
                matrix[0][j]=0;
            }
        }
        if(col0==0){
            for(int i=0;i<rows;i++){
                matrix[i][0]=0;
            }
        }
    }
};
