class Solution {
public:
    int partition(vector<int>&arr,int low,int high){
        int pivot = arr[low];
        while(i<j){
            while(arr[i]<pivot && i<=high-1){
                i++;
            }
            while(arr[j]>pivot && j>=low+1){
                j--;
            }
            if(i<j){
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[low],arr[j]);
        return j;
    }
    void qs(vector<int>&arr,int low,int high){
        if(low<high){
            int pIndex = partition(arr,low,high);
            qs(arr,low,partition-1);
            qs(arr,partition+1,high);
        }
    }
    vector<int> quickSort(vector<int>& nums) {
        qs(nums,0,nums.size()-1);
     return nums
    }
};
