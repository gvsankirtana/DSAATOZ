class Solution {
public:
void merge(vector<int>&arr,int low,int mid,int high){
    int left = low;
    int right = mid+1;
    vector<int>tmp;
    while(left<=mid&&right<=high){
        if(arr[left]<arr[right]){
           tmp.push_back(arr[left]);
           left++;
        }
        else{
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
        right++
    }
    for(int i=low;i<=high;i++){
        arr[i] = tmp[i-low];
    }
}
void ms(vector<int>&arr,int low,int high){
    if(low==high) return;
    int mid = (low+high)/2;
    ms(arr,low,mid);
    ms(arr,mid+1,high);
    merge(arr,low,mid,high);
}
    vector<int> mergeSort(vector<int>& nums) {
      ms(nums,0,n-1);
      return nums;
    }
};
