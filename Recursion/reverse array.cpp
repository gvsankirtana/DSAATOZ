class Solution{
public:
//brute force use 2 pointers l and r
//optimal solution
void rev(int i,int arr[],int n){
    if(i>=n/2)return;
    swap(arr[i],arr[n-i-1]);
    rev(i+1,arr,n);
}
    void reverse(int arr[], int n){
        rev(0,arr,n);
    }
};
