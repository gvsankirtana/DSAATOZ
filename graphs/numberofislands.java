class Solution {
    void bfs(int n,int m, int[][]vis, char[][]grid){
        Queue<Pair<Integer, Integer>> q = new LinkedList<Pair<Integer, Integer>>();
        vis[n][m]=1;
        q.add(new Pair(n,m));
        int[] drow = {-1, 0, 1, 0};
        int[] dcol = {0, 1, 0, -1};
        while (!q.isEmpty()) {
            int row = q.peek().getKey();
            int col = q.peek().getValue();
            q.remove();
            for (int i = 0; i < 4; i++) {
                int neighrow = row + drow[i];
                int neighcol = col + dcol[i];
                if (neighrow >= 0 &&
                    neighrow < grid.length &&
                    neighcol >= 0 &&
                    neighcol < grid[0].length &&
                    grid[neighrow][neighcol] == '1' &&
                    vis[neighrow][neighcol] == 0) {
                    vis[neighrow][neighcol] = 1;
                    q.add(new Pair<>(neighrow, neighcol));
                }
            }
        }
    }
    public int numIslands(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int [][] vis = new int[n][m];
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
}
