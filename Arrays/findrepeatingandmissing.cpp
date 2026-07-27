class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        //brute force method TC->O(N^3) SC->O(1)
         int n = grid[0].size();
         int repeating=-1,missing=-1;
         for(int i=1;i<=n*n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                if(grid[j][k]==i){
                    cnt++;
                }
            }
            }
            if(cnt==2) repeating = i;
            else if(cnt==0)missing = i;
         }
         return {repeating,missing};
         //better method Tc->O(N^2) SC->O(N)
         vector<int> hash(n * n + 1, 0);
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            hash[grid[i][j]]++;
            }
         }
         for(int i=1;i<=n*n;i++){
            if(hash[i]==2)repeating=i;
            else if(hash[i]==0)missing=i;
            if(repeating!=-1&&missing!=-1){
                break;
            }
         }
         return {repeating,missing};
        //optimal solution 1 TC->O(N^2) SC->O(1)
        long long n = grid.size();
        long long N = n * n;                     // total number of elements / max value
        long long sN  = N * (N + 1) / 2;
        long long s2N = N * (N + 1) * (2 * N + 1) / 6;
        long long s = 0, s2 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                s  += grid[i][j];
                s2 += (long long)grid[i][j] * (long long)grid[i][j];
            }
        }
        long long val1 = s - sN;          // repeating - missing
        long long val2 = s2 - s2N;        // repeating^2 - missing^2
        val2 = val2 / val1;               // repeating + missing
        long long x = (val1 + val2) / 2;  // repeating
        long long y = x - val1;           // missing
        return {(int)x, (int)y};
    }
};
