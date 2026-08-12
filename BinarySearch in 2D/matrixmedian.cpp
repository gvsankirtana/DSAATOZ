class Solution{
public:
//brute force nxm+nxmxlog(nxm)
//optimal solution O(log(10^9)xnxlogm)
int upperBound(vector<int>&arr,int x,int n){
    int low = 0, high = n-1;
    int ans = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>x){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
int countSmallEqual(vector<vector<int>>&matrix, int n,int m,int x){
    int cnt = 0;
    for(int i=0;i<n;i++){
        cnt+=upperBound(matrix[i],x,m);
    }
    return cnt;
}
    int findMedian(vector<vector<int>>&matrix) {
      int low = INT_MAX, high = INT_MIN;
      int n = matrix.size();
      int m = matrix[0].size();
      for(int i=0;i<n;i++){
        low = min(low,matrix[i][0]);
        high = max(high,matrix[i][m-1]);
      }
      int req = (m*n)/2;
      while(low<=high){
        int mid = (low+high)/2;
        int smallEqual = countSmallEqual(matrix,n,m,mid);
        if(smallEqual<=req) low = mid+1;
        else high = mid-1;
      }
      return low;
    }
};
