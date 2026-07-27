class Solution {
public:
long long merge(vector<int>&arr,int low,int mid,int high){
    //brute forc esolution TC->O(N^2) SC->O(1) use 2 loops and check and do counter plus 1
    //optimised solution TC->O(nlogn) SC->O(N)
    int left = low;
    int right = mid+1;
    vector<int>tmp;
    long long cnt = 0;
    while(left<=mid&&right<=high){
        if(arr[left]<arr[right]){
           tmp.push_back(arr[left]);
           left++;
        }
        else{
            cnt+=(mid-left)+1;
            tmp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        tmp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        tmp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i] = tmp[i-low];
    }
    return cnt;
}
long long ms(vector<int>&arr,int low,int high){
    long long cnt = 0;
    if(low==high) return cnt;
    int mid = (low+high)/2;
    cnt+=ms(arr,low,mid);
    cnt+=ms(arr,mid+1,high);
    cnt+= merge(arr,low,mid,high);
    return cnt;
}
   long long int numberOfInversions(vector<int> nums) {
      return ms(nums,0,n-1);
    }
};
