class Solution {
  public:   
  int lowerbound(vector<int>arr,int m,int x){
    int low = 0, high = m-1;
    int ans = m;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>=x){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
  }
  int rowWithMax1s(vector < vector < int >> & mat) {
//bruteforce method O(N*M)
//optimal solution O(Nlogm) use lowerbound(1), upperbound(0), findoccurrences(1) in binary
int ind = -1;
int cnt_max = 0;
int m = mat[0].size();
for(int i=0;i<m;i++){
    int cnt_ones =  m - lowerbound(mat[i],m,1);
    if(cnt_ones>cnt_max){
        cnt_max = cnt_ones;
        ind = i;
    }
}
return ind;
  }
};
