class Solution {
    int bfs(int row,int col, int[][]vis,int[][]grid){
       int n = grid.length;
       int m = grid[0].length;
       Queue<Pair<Integer,Integer>> q = new LinkedList<Pair<Integer,Integer>>();
       vis[row][col]=1;
       q.add(new Pair(row,col));
       int [] drow = {-1,0,1,0};
       int [] dcol = {0,1,0,-1}; 
       int area = 1;
       while(!q.isEmpty()){
           int nrow = q.peek().getKey();
           int ncol = q.peek().getValue();
           q.remove();
           for(int i=0;i<4;i++){
            int neighrow = nrow + drow[i];
            int neighcol = ncol + dcol[i];
            if(neighrow>=0&&neighrow<n&&neighcol>=0&&neighcol<m&&vis[neighrow][neighcol]==0&&grid[neighrow][neighcol]==1){
                vis[neighrow][neighcol] = 1;
                q.add(new Pair(neighrow,neighcol));
                area++;
            }
           }
       }
       return area;
    }
    public int maxAreaOfIsland(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int cnt = 0;
        int [][] vis = new int [n][m];
        int maxArea = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0&&grid[i][j]==1){
                  int area = bfs(i,j,vis,grid);
                  maxArea = Math.max(area,maxArea);
                }
            }
        }
        return maxArea;
    }
}
