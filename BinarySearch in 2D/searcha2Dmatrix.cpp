class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //brute force O(n*m)
        //optimal solution do binary search on each row O(nlogm)
        //optimal solution 2 O(log(n*m))
        if(matrix.size()==0) return false;
        int n = matrix.size();
        int m = matrix[0].size();
        int lo=0;
        int hi = (n*m)-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(matrix[mid/m][mid%m]==target){
                return true;
            }
            if(matrix[mid/m][mid%m]<target){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return false;
    }
};
