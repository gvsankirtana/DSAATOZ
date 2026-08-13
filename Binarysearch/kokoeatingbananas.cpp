class Solution {
public:
int findmax(vector<int>&arr){
    int maxi = INT_MIN;
    int n = arr.size();
    for(int i=0;i<n;i++){
        maxi = max(maxi,arr[i]);
    }
    return maxi;
}
long long calculateTotalHours(vector<int>&v,int hourly){
    long long totalH = 0;
    int n = v.size();
    for(int i=0;i<n;i++){
        totalH+=(long long)ceil((double)v[i]/(double)hourly);
    }
    return totalH;
}
    int minEatingSpeed(vector<int>& piles, int h) {
      //brute force using loops TC-> O(max(arr)xn)
      //optimal solution O(n)xlog(maxelement)
        int low = 1, high = findmax(piles);
        while(low<=high){
            int mid = (low+high)/2;
            long long totalhrs = calculateTotalHours(piles,mid);
            if(totalhrs<=h){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};
